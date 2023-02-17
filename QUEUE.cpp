// Circular Queue

#include<bits/stdc++.h> 
using namespace std;

class Queue{
    int rear,front;
    int size;
    int* arr;
    public:
        Queue(int s){
            front=rear=-1;
            size=s;
            arr=new int[s];
        }
        void enQueue(int val){
            if((front==0 && rear == size-1)||(rear == (front-1)%(size-1))){
                cout<<"Queue is Full"<<endl;
                return;
            }
            else if(front ==-1){
                front = rear = 0;
                arr[rear] = val;
            }
            else if(rear == size-1 && front != 0){
                rear = 0;
                arr[rear] = val;
	}
            else{
                rear++;
                arr[rear] = val;
            }
        }
        void dequeue(){
            if(front==-1){
                cout<<"Queue is empty"<<endl;
                return;
            }
            if(front==rear){
                front = -1;
                rear = -1;
            }
            else if(front==size-1){
                front = 0;
            }
            else{
                front++;
            }
        }
        int peek(){
            if(front==-1){
                cout<<"Queue is empty"<<endl;
                return -1;
	}
            return arr[front];
        }
};

int main(){
	Queue q(5);
    q.enQueue(1);
    q.enQueue(2);
    q.enQueue(3);
    q.enQueue(4);
    q.enQueue(5);
    //q.enQueue(6);
    //q.dequeue();
    //q.enQueue(6);
    //q.enQueue(6);
    cout<<q.peek()<<endl;
    
}