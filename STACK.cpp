#include <iostream>
using namespace std;

#define n 100

class stack{
    int* arr;//Dynamic Array
    int  top;
    public:
    stack(){
        arr = new int[n];
        top = -1;
    }
    void push(int x){
        if(top==n-1){
            cout<<"Stack is Full"<<endl;
            return;
        }
        top++;
        arr[top]=x;
    }
    void pop(){
        if(top==-1){
            cout<<"Stack is Empty"<<endl;
            return;
        }
        top--;
    }
    int Top(){
        if(top==-1){
            cout<<"No Element in Stack"<<endl;
        }
        return arr[top];
    }
    bool empty(){
        return top==-1;
    }
};

int main() {
	// your code goes here
	stack st;
	st.push(1);
	st.push(2);
	st.push(5);
	cout<<st.Top()<<endl;
	st.pop();
	st.pop();
	st.pop();
	st.pop();
	cout<<st.empty()<<endl;
	return 0;
}
