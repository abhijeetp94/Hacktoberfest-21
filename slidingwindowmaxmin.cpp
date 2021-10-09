#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define f(i,a,n) for(int i=a;i<n;i++)
#define vi vector<ll>
#define vp vector<pi>
#define mpi unordered_map<ll,ll>
#define si unordered_set<ll>
#define str string
#define st stack<ll> 
#define q queue<ll> 
#define dq deque<ll>
#define pi pair<ll,ll>
#define mps unordered_map<str,ll>
#define endl cout<<endl
#define mod 1000000007
int main(){
    int n,k;
    cin>>n>>k;
    vi a(n,0);
    f(i,0,n)
    cin>>a[i];
    dq dqe(k);
    vi ans;
    f(i,0,k){
        while(!dqe.empty()&&a[i]<=a[dqe.back()])//>for max
        dqe.pop_back();

        dqe.push_back(i);
    }
    f(i,k,n){
        
        ans.push_back(a[dqe.front()]);
        
        while(!dqe.empty()&&dqe.front()<=i-k)
        dqe.pop_front();
        
        while(!dqe.empty()&&a[i]<=a[dqe.back()])//>for max
        dqe.pop_back();
       
        
        dqe.push_back(i);
        
    }
    ans.push_back(a[dqe.front()]);
    endl;
    for(ll i :ans)
    cout<<i<<" ";
}