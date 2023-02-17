#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
	ll t,ans,i,j,n;
	cin>>t;
	for(int i=0;i<t;i++){
	    cin>>n;
	    ll a[n],inc[n],dec[n];
	    for(int i=0;i<n;i++){
	        cin>>a[i];
	    }
	    inc[n-1]=dec[n-1]=1;
	    for(int i=n-2;i>=0;i--){
	        if(a[i]>a[i+1]){
	            dec[i] = dec[i+1] + 1;
	        }
	        else{
	            dec[i] = 1;
	        }
	        if(a[i]<a[i+1]){
	            inc[i] = inc[i+1] + 1;
	        }
	        else{
	            inc[i] = 1;
	        }
	    }
	    ans = 0;
	    for(int i=0;i<n;i++){
	        if(inc[i]>1){ //Increasing Subarrays
	            ans = ans + inc[i];
	        }
	        else if(dec[i]>1){ //Decreasing Subarrays
	            ans = ans + dec[i];
	            j = i + dec[i];
	            if(j<n){ // Decreasing to Increasing subarrays
	                ans = ans + inc[j];
	            }
	        }
	        else{
	            ans++;
	        }
	    }
	    cout<<ans<<endl;
	}
	return 0;
}
