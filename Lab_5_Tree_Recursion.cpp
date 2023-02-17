#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* right;
    node* left;

    node(int d){
        this->data=d;
        this->left=NULL;
        this->right=NULL;
    }
};

node* buildTree(node* root){

    cout<<"Enter the data: ";
    int data;
    cin>> data;
    root=new node(data);

    if (data==-1)
    {
        return NULL;
    }
    
    cout<< "Enter data for inserting in left of "<<data<<endl;
    root->left= buildTree(root->left);
    cout<< "Enter data for inserting in Right of "<<data<<endl;
    root->right= buildTree(root->right);
    return root;
}

void preorder(node* root){
    if (root==NULL)
    {
        return;
    }
    
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
    
}

void inorder(node* root){
    if (root==NULL)
    {
        return;
    }
    
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
    
}

void postorder(node* root){
    if (root==NULL)
    {
        return;
    }
    
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
    
}


int main(){
     
    node* root=NULL;

    //creating a tree

    root=buildTree(root);

    int s; 
    
    while(s!=4){
    cout<<"\n"<<"Enter your choice: "<<"\n"<<"1.PreOrder Traversal"<<"\n"<<"2.InOrder Traversal"<<"\n"<<"3.PostOrder Traversal"<<"\n"<<"4.Exit"<<endl;
    cin>>s;

    switch (s)
    {
    case 1:
        cout<<"PreOrder Traversal is:  ";
        preorder(root);
        break;
    case 2:
        cout<<"InOrder Traversal is:  ";
        inorder(root);
        break;
    case 3:
        cout<<"PostOrder Traversal is:  ";
        postorder(root);
        break;
    case 4:
        break;
    default:
        break;
    }

    }
   return 0;
    
}