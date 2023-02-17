// Height and Diameter in Binary Tree

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

int calcHeight(node* root){
    if(root==NULL){
        return 0;
    }
    int lHeight = calcHeight(root->left);
    int rHeight = calcHeight(root->right);
    return max(lHeight,rHeight) + 1;
}

int CalcDiameter(node* root,int* height){// O(N)
    if(root==NULL){
        return 0;
    }
    int lh=0,rh=0;
    int lDiameter = CalcDiameter(root->left,&lh);
    int rDiameter = CalcDiameter(root->right,&rh);
    
    int currDiameter = lh + rh + 1;
    *height = max(lh,rh) + 1;
    return max(currDiameter,max(lDiameter,rDiameter));
}

int calcDiameter(node* root){ // O(N^2)
    if(root==NULL)
        return 0;
    int lHeight = calcHeight(root->left);
    int rHeight = calcHeight(root->right);
    int currDiameter = lHeight + rHeight + 1;
    int lDiameter = calcDiameter(root->left);
    int rDiameter = calcDiameter(root->right);
    
    return max(currDiameter,max(lDiameter,rDiameter));
}


int main() {
    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);
    cout<<calcHeight(root)<<endl;
    cout<<calcDiameter(root)<<endl;
    int height = 0;
    cout<<CalcDiameter(root,&height)<<endl;
	return 0;
}
