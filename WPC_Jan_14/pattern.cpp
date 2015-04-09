#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;

typedef long long ll;
const ll mod=1e9+6;
const ll modp=1e9+7;
ll power(ll n,ll k){
	if(k==0)
		return 1;
	else if(k==1)
		return n;
	ll val=power(n*n,k/2);
	// cout<<" val "<<val<<endl;
	if(k%2==0){
		// cout<<"r "<<val<<endl;
		if(val>=mod)
			return val%mod;
		else
			return val;
	}
	else{
		if(val*n>=mod)
			return (val*n)%mod;
		else
			return val*n;
	}
}

ll powern(ll n,ll k){
	if(k==0)
		return 1;
	else if(k==1)
		return n;
	ll val=power(n*n,k/2);
	// cout<<" val "<<val<<endl;
	if(k%2==0){
		// cout<<"r "<<val<<endl;
		if(val>=modp)
			return val%modp;
		else
			return val;
	}
	else{
		if(val*n>=modp)
			return (val*n)%modp;
		else
			return val*n;
	}
}

int main() {
	int t;
	cin>>t;
	while(t--){
		ll k,n;
		cin>>k>>n;
		if(n>=4){
			n-=3;
			ll val=power(2,n);
			ll ans=powern(k,val);
			cout<<ans<<endl;
		}	
		else{
			if(n==1)
				cout<<"1\n";
			else if(n==2 || n==3)
				cout<<k<<endl;
		}
	}
	return 0;
}