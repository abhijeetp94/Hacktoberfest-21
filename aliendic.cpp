#include<bits/stdc++.h>
using namespace std;
class Solve{
    bool dfs(vector<int> al[],vector<int> &visited,int j){
        visited[j]=1;
        for(int i : al[j]){
            if(visited[i]==2)
            continue;
            if(visited[i]==1){              /****  Finding cycle in directed graph  ****/
                return true;
            }
            if(dfs(al,visited,i))
            return true;
        }
        visited[j]=2;
        return false;
    }
    vector<int> solve(vector<string> &words,int n){
        vector<int> al[n],visited(n,0),result;
        for(int i=0;i<n-1;i++){
            string c=words[i];
            string s=words[i+1];
            for(int j=0;j<min(c.size(),s.size());j++){
                if(c[j]!=s[j]){
                    al[c[i]-'a'].push_back(s[j]-'a');
                    break;}}
        }
        return topologicalSort(al,visited,result);
    }
    vector<int> topologicalSort(vector<int> al[],vector<int> &visited,vector<int> &result){
        //checking cycle
        int n=visited.size();
        for(int i=0;i<n;i++){
            if(visited[i]==0)
                if(dfs(al,visited,i)){
                    cout<<"Contains cycle\n";
                    return result;}
                    }
        //if no cycle then topological sort
        stack<int> ans; 
        for(int i=0;i<n;i++){
            if(visited[i]==0)
                dfs2(al,visited,i,ans);}
        while(!ans.empty()){
            result.push_back(ans.top());
            ans.pop();
        }
        return result;}
    void dfs2(vector<int> al[],vector<int> &visited,int j,stack<int> &ans){
        visited[j]=1;
        for(int i : al[j]){
            if(visited[i]==0)
                dfs2(al,visited,i,ans);
        }
        ans.push(j);
        return; 
    }
};
int main(){

}