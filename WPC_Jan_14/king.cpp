#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;
typedef long long ll;

ll power(ll n,ll k){
	if(k==0)
		return 1;
	else if(k==1)
		return n;
	ll val=power(n*n,k/2);
	// cout<<" val "<<val<<endl;
	if(k%2==0){
		// cout<<"r "<<val<<endl;
		return val;
	}
	else{

		// cout<<"r - "<<val*k<<endl;
		return val*n;
	}
}

ll intlog(double base, double x) {
    return (ll)(log(x) / log(base));
}

ll get(ll n,ll k){
	if(n==0)
		return 0;
	ll maxpow=intlog(k,n);
	ll u=power(k,maxpow);
	ll rem=n%u;
	// cout<<"pow "<<power(k,maxpow)<<endl;
	// cout<<"maxpow "<<maxpow<<" rem "<<rem<<endl;
	return n/u+get(rem,k);
}

int main() {
	ll t,n,k;
	cin>>t;
	while(t--){
		cin>>n>>k;
		if(k==1){
			cout<<n<<endl;
			continue;
		}
		ll ans=get(n,k);
		cout<<ans<<endl;
	}
	return 0;
}