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
#define pi pair<ll,ll>
#define mps unordered_map<str,ll>
#define mod 1000000007
struct BST{
    int data;
    int freq;
    struct BST *right,*left;
};
#define BSTREE struct BST
BSTREE *insertion(BSTREE *root,int k){
    if(root==NULL){
        root=(BSTREE *)malloc(sizeof(BSTREE));
        root->data=k;
        root->left=NULL;
        root->right==NULL;
        root->freq=1;
    }
    else if(root->data>k){
        root->left=insertion(root->left,k);
    }
    else if(root->data<k){
        root->right=insertion(root->right,k);
    }
    else{
        root->freq++;
    }
    return root;
}
BSTREE *deletion(BSTREE *root,int k){
    if(root==NULL){
        return NULL;
    }
    else if(root->data>k){
        root->left=deletion(root->left,k);
    }
    else if(root->data<k){
        root->right=deletion(root->right,k);
    }
    else if(root->freq>1){
        root->freq--;
    }
    else{
        if(root->right==NULL&&root->left!=NULL){
            return root->left;
        }
        else if(root->left==NULL||root->right==NULL)
        {
            return root->right;   
        }
        else{
            BSTREE *temp=root->right;
            while(temp->left!=NULL)
            temp=temp->left;
            root->data=temp->data;
            root->right=deletion(root->right,temp->data);
        }

    }
    return root;
}
int main(){

}