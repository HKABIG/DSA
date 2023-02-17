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

void infixtoprefix(string s){
    string r = s;
    stack<char> st;
    reverse(r.begin(),r.end());
    string res = "";
    for(int i=0;i<r.size();i++){
        if(r[i]>='a' && r[i]<='z'){
            res += r[i];
        }
	else if(r[i]==')'){
            st.push(r[i]);
        }
        else if(r[i]=='('){
            while(st.top()!=')'){
                res += st.top();
                st.pop();
            }
            st.pop();
        }
        else{
            while(!st.empty() && prec(r[i])<=prec(st.top())){
                res += st.top();
                st.pop();
            }
            st.push(r[i]);
        }
    }
    while(!st.empty()){
        res += st.top();
        st.pop();
    }
    reverse(res.begin(),res.end());
    cout<<res<<endl;
}

int main(){
	infixtoprefix("a+b*c^d-e^f+g*h-i");
}