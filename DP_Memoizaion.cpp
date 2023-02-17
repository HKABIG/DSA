// Dynamic Programming Using Memoizaion;
#include<bits/stdc++.h> 
using namespace std;

int fib(int n,vector<int> dp){
    if(n<=1){
        return n;
    }
    if(dp[n]!=-1){
        return dp[n];
    }
    dp[n] = fib(n-1,dp)+fib(n-2,dp);
    return dp[n];
}

int main(){
    int n;
    cin>>n;
    vector<int> dp;
    for(int i=0;i<=n;i++){
        dp.push_back(-1);
    }
    cout<<fib(n,dp)<<endl;
    return 0;
}