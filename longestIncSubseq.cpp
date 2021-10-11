//Program to find the length of longest increasing subsequesnce in an array.
//Dynamic programming will be used here.

#include <bits/stdc++.h>
using namespace std;

int lis(const vector<int> &A)
{
    int n = A.size();
    if(n == 0) return 0;
    int cur = 1;
    int max = 0;
    int best = 1;
    int dp[n];
    memset(dp, 0, sizeof(dp));
    
    dp[0] = 1;
    for(int i = 1; i<n; i++)
    {
        max = 0;
        cur = 1;
        for(int j = 0; j<i; j++)
        {
            if(A[i]<=A[j])
            {
                cur = 1;
            }
            else
            {
                cur = 1+dp[j];
            }
            if(max<cur) max = cur;
        }
        dp[i] = max;
        if(max>best) best = max;
    }
    
    return best;
}

int main()
{
    int n;
    cout<<"Enter size of array: ";
    cin>>n;
    
    vector<int> v(n);
    cout<<"Enter the elements:\n";
    for(int i = 0; i<n; i++) cin>>v[i];
    
    cout<<"The length of longest increasing subsequesnce is: "<<lis(v);
    return 0;
}
