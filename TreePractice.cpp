#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* right;
    node* left;
    node(int val){
        this->data = val;
        this->left = NULL;
        this->right = NULL;
    }
};

node* buildTree(node* root){
    cout<<"Enter the data: ";
    int data;
    cin>>data;
    root = new node(data);
    if(data == -1){
        return NULL;
    }
    cout<<"Enter the data to the left of "<<data<<endl;
    root->left = buildTree(root->left);
    cout<<"Enter the data to the right of "<<data<<endl;
    root->right = buildTree(root->right);
    
    return root;
}

void inorder(node* root){
    if(root==NULL){
        return ;
    }
    inorder(root->left);
    cout<<root->data<<"->";
    inorder(root->right);
}

void preorder(node* root){
    if(root==NULL){
        return ;
    }
    cout<<root->data<<"->";
    preorder(root->left);
    preorder(root->right);
}

void postorder(node* root){
    if(root==NULL){
        return ;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<"->";
}

void inorderStack(node* root){
    stack<node* > st;
    node* temp = root;
    while(temp!=NULL || !st.empty()){
        while(temp!=NULL){
            st.push(temp);
            temp=temp->left;
        }
        temp = st.top();
        st.pop();
        cout<<temp->data<<"->";
        temp = temp->right;
    }
}

void preorderStack(node* root){
    stack<node* > st;
    node* temp = root;
    while(temp!=NULL || !st.empty()){
        while(temp!=NULL){
            cout<<temp->data<<"->";
            if(temp->right){
                st.push(temp->right);   
            }
            temp = temp->left;
        }
        if(!st.empty()){
            temp = st.top();
            st.pop();
        }
    }
}

int main(){
    node* root = NULL;
    root = buildTree(root);
    cout<<"Printing inorder traversal"<<endl;
    inorder(root);
    cout<<"NULL"<<endl;
    cout<<"Printing preorder traversal"<<endl;
    preorder(root);
    cout<<"NULL"<<endl;
    cout<<"Printing postorder traversal"<<endl;
    postorder(root);
    cout<<"NULL"<<endl;
    inorderStack(root);
    cout<<"NULL"<<endl;
    preorderStack(root);
    cout<<"NULL"<<endl;
}
