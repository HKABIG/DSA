#include<bits/stdc++.h> 
using namespace std;

int prec(char s){
    if(s=='^'){
        return 3;
    }
    else if(s=='*' || s=='/'){
        return 2;
    }
    else if(s=='-' || s=='+'){
        return 1;
    }
    else{
        return -1;
    }
}

void infixtopostfix(string s){
    stack<char> st;
    string res;
    for(int i=0;i<s.size();i++){
        if((s[i]>='a' && s[i]<='z')){
            res += s[i];
        }
        else if(s[i]=='('){
            st.push(s[i]);
	     }
        else if(s[i]==')'){
            while(st.top()!='('){
                res+=st.top();
                st.pop();
            }
            st.pop();
        }
        else{
            while(!st.empty() && prec(s[i])<=prec(st.top())){
                res+=st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }
    while(!st.empty()){
        res += st.top();
        st.pop();
    }
    cout<<res<<endl;
}

int main(){
	infixtopostfix("a+b*c^d-e^f+g*h-i");
}