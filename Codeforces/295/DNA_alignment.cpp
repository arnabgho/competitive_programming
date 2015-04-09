#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;
typedef long long ll;
std::vector<ll> v(4,0);
int main() {
	ll n;
	string s;
	cin>>n>>s;
	for (ll i = 0; i < n; ++i)
	{
		if(s[i]=='A')
			v[0]++;
		if(s[i]=='T')
			v[1]++;
		if(s[i]=='G')
			v[2]++;
		if(s[i]=='C')
			v[3]++;
	}
	ll mx=0;
	for (ll i = 0; i <4 ; ++i)
	{
		mx=max(mx,v[i]);/* code */
	}
	ll c=0;
	for (ll i = 0; i <4 ; ++i)
	{
		c+=(v[i]==mx);
	}
	ll ans=1;
	ll mod=1e9+7;
	for (ll i = 0; i < n; ++i)
		ans=(ans*c)%mod;
	if(ans<0)
		ans+=mod;
	cout<<ans<<endl;
	return 0;
}