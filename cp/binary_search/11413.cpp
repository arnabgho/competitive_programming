#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;
typedef long long ll;
std::vector<ll> v;
ll n,m;
bool checkValid(ll cap){
	ll numUsed=1;
	ll cur=0;
	for (ll i = 0; i < n; ++i)
	{
		if(cur+v[i]<=cap){
			cur+=v[i];continue;
		}

		if(v[i]>cap) return 0;
		numUsed++;
		cur=v[i];
	}
	return numUsed<=m;
}

int main() {
	while(scanf("%lld %lld",&n,&m)!=EOF){
		v.clear();
		for (ll i = 0; i < n; ++i)
		{
			ll x;cin>>x;v.push_back(x);
		}
		ll lo,hi;
		hi=accumulate(v.begin(), v.end(),0);
		lo=0;
		ll ans=1e18;
		while(lo<hi){
			ll mid=lo+(hi-lo)/2;
			if(checkValid(mid)){
				ans=min(ans,mid);
				hi=mid;
			}
			else
				lo=mid+1;
		}
		cout<<ans<<endl;
	}
	return 0;
}