#include <iostream>
#include <stack>
using namespace std;

void InserAtBottom(stack<int> &st,int ele){
    if(st.empty()){
        st.push(ele);
        return;
    }
    int topele = st.top();
    st.pop();
    InserAtBottom(st,ele);
    
    st.push(topele);
    
}

void recurrsiveReverse(stack<int> &st){
    if(st.empty()){
        return;
    }
    int ele = st.top();
    st.pop();
    recurrsiveReverse(st);
    InserAtBottom(st,ele);
    
}

int main() {
	// your code goes here
	stack <int> st;
	st.push(1);
	st.push(2);
	st.push(3);
	st.push(4);
	st.push(5);
	
	recurrsiveReverse(st);
	while(!st.empty()){
	    cout<<st.top()<<" ";
	}cout<<endl;
	
	return 0;
}
