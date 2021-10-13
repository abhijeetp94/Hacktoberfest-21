#include <array>
#include <chrono>
#include <iostream>

class Sudoku {
  using count_t = std::array<uint8_t, 10>;

  std::array<std::array<uint8_t, 9>, 9> board{};
  std::array<count_t, 9> row_cnt{};
  std::array<count_t, 9> col_cnt{};
  std::array<count_t, 9> blk_cnt{};

public:

  Sudoku(std::array<std::array<uint8_t, 9>, 9> brd) {
    for (int r = 0; r < 9; r++) {
      for (int c = 0; c < 9; c++) {
        try_set(r, c, brd[r][c]);
      }
    }
  }

  uint8_t get(int r, int c) { return board[r][c]; }

  bool try_set(int r, int c, uint8_t val) {
    int b = 3 * (r / 3) + (c / 3);
    if (board[r][c] | row_cnt[r][val] | col_cnt[c][val] | blk_cnt[b][val]) {
      return false;
    }
    board[r][c] = val;
    row_cnt[r][val]++;
    col_cnt[c][val]++;
    blk_cnt[b][val]++;
    return true;
  }

  void clear(int r, int c) {
    int b = 3 * (r / 3) + (c / 3);
    uint8_t val = board[r][c];
    board[r][c] = 0;
    row_cnt[r][val]--;
    col_cnt[c][val]--;
    blk_cnt[b][val]--;
  }

  bool solved() {
    for (int i = 0; i < 9; i++) {
      for (int val = 1; val < 10; val++) {
        if (row_cnt[i][val] != 1 |
            col_cnt[i][val] != 1 |
            blk_cnt[i][val] != 1) { return false; }
      }
    }
    return true;
  }
};

bool solve(Sudoku& s, int r = 0, int c = 0) {
  if (c == 9) {
    return s.solved();
  }

  int next_r = (r + 1) % 9;
  int next_c = c + ((r + 1) / 9);
  if (s.get(r, c) != 0) {
    return solve(s, next_r, next_c);
  }

  for (uint8_t val = 1; val < 10; val++) {
    if (!s.try_set(r, c, val)) {
      continue;
    }
    if (solve(s, next_r, next_c)) {
      return true;
    }
    s.clear(r, c);
  }

  return false;
}

std::ostream& operator<<(std::ostream& os, Sudoku& s) {
  for (int r = 0; r < 9; r++) {
    os << "|";
    for (int c = 0; c < 9; c++) {
      if (s.get(r, c)) {
        os << " " << (int)s.get(r, c) << " |";
      } else {
        os << "   |";
      }
    }
    os << "\n";
  }
  return os;
}

int main() {
  Sudoku s{{{
    {{5, 3, 0, 0, 7, 0, 0, 0, 0}},
    {{6, 0, 0, 1, 9, 5, 0, 0, 0}},
    {{0, 9, 8, 0, 0, 0, 0, 6, 0}},
    {{8, 0, 0, 0, 6, 0, 0, 0, 3}},
    {{4, 0, 0, 8, 0, 3, 0, 0, 1}},
    {{7, 0, 0, 0, 2, 0, 0, 0, 6}},
    {{0, 6, 0, 0, 0, 0, 2, 8, 0}},
    {{0, 0, 0, 4, 1, 9, 0, 0, 5}},
    {{0, 0, 0, 0, 8, 0, 0, 7, 9}}
  }}};
  auto begin_ts = std::chrono::high_resolution_clock::now();
  solve(s);
  auto end_ts = std::chrono::high_resolution_clock::now();
  std::chrono::nanoseconds dur = end_ts - begin_ts;
  std::cout << "solver took " << (dur.count() / 1e6) << "ms" << std::endl;

  std::cout << s << std::endl;
}

