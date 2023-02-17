//Count the number of nodes and total sum of nodes

#include <bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* left;
    node* right;
    node(int val){
        data = val;
        left=NULL;
        right=NULL;
    }
};

int CountNodes(node* root){
    if(root==NULL)
        return 0;
    return CountNodes(root->left)+ CountNodes(root->right) + 1;
}

int sumNodes(node* root){
    if(root==NULL)
        return 0;
    return sumNodes(root->left) + sumNodes(root->right) + root->data;
}


int main() {
    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);
    cout<<CountNodes(root)<<endl;
    cout<<sumNodes(root)<<endl;
	return 0;
}
