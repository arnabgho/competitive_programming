#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;

typedef long long ll;
map<ll,ll> m;
std::vector<ll> v(5500,0);
ll n,k;

ll check(ll x){
	ll lo=0;ll hi=n-1;
	ll pos=-1;
	while(lo<=hi){
		ll mid=lo+(hi-lo)/2;
		if(v[mid]<=x){
			pos=max(pos,mid);
			lo=mid+1;
		}
		else{
			hi=mid-1;
		}
	}
	// cout<<"pos "<<pos<<endl;
	if(pos==-1)
		return -1;
	ll ans=1e9;
	for (int i = pos; i >=0 ; --i)
	{
		for(ll j=1;j<=k;j++){
			ll val=x-v[pos]*j;
			if(val==0)
				ans=min(ans,j);
			if(m.find(val)!=m.end()) {
				if(m[val]+j<=k){
					ans=min(ans,m[val]+j);
				}
			}
		}
	}
	if(ans==1e9) return -1;
	else return ans;
}

int main() {
	ll q,x;
	cin>>n>>k;
	for (int i = 0; i < n; ++i)
	{
		cin>>v[i];
	}

	for (int i = n-1; i >=0 ; --i)
	{
		for (ll j = 1; j <=k ; ++j)
		{
			ll val=v[i]*j;
			if(m.find(val)==m.end()){
				m[val]=j;
			}
			else
				m[val]=min(m[val],j);
		}
	}

	cin>>q;
	for (int i = 0; i < q; ++i)
	{
		cin>>x;
		cout<<check(x)<<endl;
	}

	return 0;
}