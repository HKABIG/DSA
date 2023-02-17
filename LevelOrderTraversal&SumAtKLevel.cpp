//Level order traversal and sum at k level

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

int sumAtK(node* root,int k){
    if(root==NULL){
        return -1;
    }
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    int level = 0;
    int sum = 0;
    while(!q.empty()){
        node* Node = q.front();
        q.pop();
        if(Node!=NULL){
            if(level==k){
                sum += Node->data;
            }
            if(Node->left)
                q.push(Node->left);
            if(Node->right)
                q.push(Node->right);
        }
        else if(!q.empty()){
            q.push(NULL);
            level++;
        }
    }
    return sum;
}

void printLevelOrder(node* root){
    if(root==NULL){
        return ;
    }
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    
    while(!q.empty()){
        node* Node = q.front();
        q.pop();
        if(Node!=NULL){
            cout<<Node->data<<" ";
            if(Node->left)
                q.push(Node->left);
            if(Node->right)
                q.push(Node->right);
        }
        else if(!q.empty())
            q.push(NULL);
    }
    cout<<endl;
}

int main() {
    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);
    printLevelOrder(root);
    cout<<sumAtK(root,2)<<endl;
	return 0;
}
