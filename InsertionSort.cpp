#include<bits/stdc++.h> 
using namespace std;

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=1;i<n;i++){
        key = a[i];
        j=i-1;
        for(int j=0;j<n;j++){
            if(a[j]>key){
                a[j+1]=a[j];
            }
            key = a[j+1];
        }
    }
}