#include <bits/stdc++.h>
using namespce std;

void Swap(int a,int b){
    a += b;
    b = a - b;
    a = a - b;
}

int main(){
    int a = 10;
    int b = 11;
    Swap(a,b);
    cout<<"a="<<a<<endl;
    cout<<"b="<<b<<endl;
    return 0;
}