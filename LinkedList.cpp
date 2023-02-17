#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* next;
    
    node(int val){
        data=val;
        next=NULL;
    }
};

void insertAtTail(node* &head,int val){//Calling the head by reference
    node* n = new node(val);
    if(head==NULL){
        head=n;
        return;
    }
    node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=n;
}

void insertAtHead(node* &head,int val){
    node* n = new node(val);
    n->next = head;
    head    = n;
}

bool search(node* head,int key){
    node* temp = head;
    while(temp!=NULL){
        if(temp->data==key){
            return true;
        }
        temp=temp->next;
    }
    return false;
}

void display(node* head){
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
void deletehead(node* &head,int val){
    node* temp=head;
    head=head->next;
    delete temp;
}

void deletion(node* &head,int val){
    if(head==NULL){
        return;
    }
    if(head->next==NULL){
        deletehead(head,val);
        return;
    }
    node* temp=head;
    while(temp->next->data!=val){
        temp=temp->next;
    }
    node* todelete = temp->next;
    temp->next=temp->next->next;
    delete todelete;
}
node* reverse(node* &head){
    node* prevptr=NULL;
    node* currptr=head;
    node* nextptr;
    
    while(currptr!=NULL){
        nextptr=currptr->next;
        currptr->next=prevptr;
        
        prevptr=currptr;
        currptr=nextptr;
    }
    return prevptr;
}

node* reverseRecursive(node* head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    node* newhead= reverseRecursive(head->next);
    head->next->next=head;
    head->next=NULL;
    
    return newhead;
}


int main(){
    node* head=NULL;
    insertAtTail(head,4);
    insertAtTail(head,5);
    insertAtTail(head,6);
    display(head);
    insertAtHead(head,7);
    display(head);
    cout<<search(head,7);
    //deletion(head,4);
    //display(head);
    //node* newhead=reverse(head);
    //display(newhead);
    node* newhead=reverseRecursive(head);
    display(newhead);
}