#include <bits/stdc++.h>
using namespace std;

bool BracketsBalanced(string s){
    stack<char> stack;
    for(int i=0;i<s.length();i++){
        if(stack.empty()){
            stack.push(s[i]);
        }
        else if((stack.top()=='(' && s[i]==')')||(stack.top()=='{' && s[i]=='}')||(stack.top()=='[' && s[i]==']')){
            stack.pop();
        }
        else{
            stack.push(s[i]);
        }
    }
    if(stack.empty()){
        return true;
    }
    else{
        return false;
    }
}

int main() {
	// your code goes here
	string s;
	cin>>s;
	if(BracketsBalanced(s)){
	    cout<<"The String is Balanced"<<endl;
	}
	else{
	    cout<<"The String is not Balanced"<<endl;
	}
	return 0;
}
