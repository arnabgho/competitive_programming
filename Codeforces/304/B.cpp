#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;
typedef long long ll;
std::vector<ll> v(10000,0);
int main() {
	ll n;
	cin>>n;
	for (ll i = 0; i < n; ++i)
	{
		ll x;cin>>x;v[x]++;
	}
	ll ans=0;
	for (ll i = 1; i <=n; ++i)
	{
		if(v[i]<=1) continue;
		for (ll j = i+1; j <=3*n && v[i]>=2 ; ++j)
		{
			if(v[j]==0){
				v[j]++;
				v[i]--;
				ans+=(j-i);
			}
		}

	}
	cout<<ans<<endl;
	return 0;
}