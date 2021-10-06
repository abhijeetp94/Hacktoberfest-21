#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class TreeNode{
public:
	int data;
	TreeNode *leftChild;
	TreeNode *rightChild;

	TreeNode(){data = 0; this->leftChild = nullptr; this->rightChild = nullptr;};
	TreeNode(int data){this->data = data; this->leftChild = nullptr; this->rightChild = nullptr;};
};

TreeNode* insert(TreeNode* root, int key){
	if(root == nullptr){
		root = new TreeNode(key);
		return root;
	}
	if(root->data < key){
		root->rightChild = insert(root->rightChild, key);
	}
	else if(root->data > key){
		root->leftChild = insert(root->leftChild, key);
	}

	return root;
}

TreeNode* generateFromPreOrder(vector<int>& pre, int mini, int maxi){
	static int prei=0;
	if(prei>=pre.size()){
		return nullptr;
	}
	int val = pre[prei];
	if(pre[prei] > maxi or pre[prei] < mini){
		return nullptr;
	}
	TreeNode* root = new TreeNode(pre[prei]);
	prei++;

	root->leftChild = generateFromPreOrder(pre, mini, val-1);

	root->rightChild = generateFromPreOrder(pre, val+1, maxi);
	
	
	return root;
}

int heightTree(TreeNode* root){
	if(root == nullptr)
		return 0;

	int leftheight = heightTree(root->leftChild);
	int rightheight = heightTree(root->rightChild);

	return 1 + max(leftheight, rightheight);
}

TreeNode* inSucc(TreeNode* root){
	while(root and root->leftChild){
		root = root->leftChild;
	}
	return root;
}


TreeNode* inPred(TreeNode* root){
	while(root and root->rightChild){
		root = root->rightChild;
	}
	return root;
}


TreeNode* deleteNode(TreeNode* root, int key){
	if(root==nullptr){
		return root;
	}
	if(root->leftChild==nullptr and root->rightChild==nullptr){
		delete root;
		root = nullptr;
		return nullptr;
	}
	if(key>root->data){
		root->rightChild = deleteNode(root->rightChild, key);
	}
	else if(key<root->data){
		root->leftChild = deleteNode(root->leftChild, key);
	}
	else {
		if(heightTree(root->leftChild) < heightTree(root->rightChild)){
			TreeNode* suc = inSucc(root->rightChild);
			root->data = suc->data;
			root->rightChild = deleteNode(root->rightChild, suc->data);
		} else{
			TreeNode* pred = inPred(root->leftChild);
			root->data = pred->data;
			root->leftChild = deleteNode(root->leftChild, pred->data);
		}

	}

	return root;
}

void inOrder(TreeNode* root){
	if(root==nullptr)
		return;
	inOrder(root->leftChild);
	cout << root->data << " ";
	inOrder(root->rightChild);
}

int main(){
	TreeNode* root = new TreeNode(50);
	int k = 0;
	cin >> k;
	cout << endl;
	vector<int> pre(k);
	for(int i=0;i<k;i++){
		cin >> pre[i];
	}

	root = generateFromPreOrder(pre, INT_MIN, INT_MAX);
	cout << endl;
	inOrder(root);
	deleteNode(root, 50);
	cout << endl;
	inOrder(root);

	return 0;
}