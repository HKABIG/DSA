#include<bits/stdc++.h> 
using namespace std;

class node{
     public:
    int data;
    node* next;
    node(int val){
        data = val;
        next = NULL;
    }
};

class Queue{
    //public:
    node* front;
    node* back;
    public:
    Queue(){
        front = NULL;
        back  = NULL;
    }
    void push(int x){
        node* n = new node(x);
        if(front==NULL){
            front = n;
            back  = n;
            return;
        }
        back->next = n;
        back = n;
    }
    void pop(){
        if(front==NULL){
            cout<<"No elements to pop"<<endl;
            return;
        }
        node* todelete=front;
        front = front->next;
        delete todelete;
    }
    int peek(){
        if(front==NULL){
            return -1;
        }
        return front->data;
    }
    bool empty(){
        if(front==NULL){
            return true;
        }
        return false;
    }
    
};

int main(){
    Queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    cout<<q.peek()<<endl;
    cout<<q.empty()<<endl;
    q.pop();
    q.pop();
    cout<<q.peek()<<endl;
    return 0;
}