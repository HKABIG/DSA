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

string infixtoprefix(string s){
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
    return res;
}

void prefixEvaluation(string r){
    stack<int> st;
    for(int i=r.size()-1;i>=0;i--){
        if(r[i]>='0' && r[i]<='9'){
            st.push(int(r[i])-48);
        }
        else{
            int op1 = st.top();
            st.pop();
            int op2 = st.top();
            st.pop();
            switch(r[i]){
                case '+':
                    st.push(op1+op2);
                    break;
                case '-':
                    st.push(op1-op2);
                    break;
                case '*':
                    st.push(op1*op2);
                    break;
                case '/':
                    st.push(op1/op2);
                    break;
                case '^':
                    st.push(op1^op2);
		                    break;
            }
        }
    }
    cout<<st.top()<<endl;
    
}

int main(){
    string result = infixtoprefix("1+2*3^4-5^6+7*8-9");
    cout<<result<<endl;
    prefixEvaluation("+9*26");
}