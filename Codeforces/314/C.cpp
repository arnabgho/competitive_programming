#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;
typedef long long ll;
map<ll,ll> DP;
int main() {
	ll n,k;
	cin>>n>>k;
	for (int i = 0; i < n; ++i)
	{
		ll x;
		cin>>x;
		DP[x]++;
	}
	ll ans=0;
	for (std::map<ll,ll>::iterator it=DP.begin();it!=DP.end();++it)
	{
		ll n=it->first;
		ans+=DP[n]*DP[n*k]*DP[n*k*k];
	}
	cout<<ans<<endl;
	return 0;
}