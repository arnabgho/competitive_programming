#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;
typedef long long ll;
typedef pair<ll,ll> pi;
const double eps=1e-9;

long long H(int n){
	long long res = 0;
	for( int i = 1; i <= n; i=i+1 ){
		res = (res + n/i);
	}
	return res;
}

int main() {
	ll t;
	cin>>t;
	for (ll cas = 1; cas <= t; ++cas)
	{
		/* code */
		for (int i = 1; i <=30 ; ++i)
		{
			cout<<"n "<<i<<" H(n) "<<H(i)<<endl;
		}

		ll ans=0;
		printf("Case #%lld: %lld",cas,ans);
	}
	return 0;
}