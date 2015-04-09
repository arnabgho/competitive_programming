#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;

typedef long long ll;

int main() {
	int t;
	cin>>t;
	while(t--){
		ll n,s;
		cin>>n>>s;
		
		ll lo=0;
		ll hi=n;
		ll ans=0;

		while(lo<=hi){
			ll k=lo+(hi-lo)/2;
			if(2*s>=(2*n+k*k-k)){
				ans=max(ans,k);
				lo=k+1;
			}
			else{
				hi=k-1;
			}
		}
		cout<<n-ans<<endl;
	}
	return 0;
}