#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;
typedef long long ll;
typedef pair<ll,ll> pi;
std::vector<ll> v;
map<ll,ll> DPleft,DPright;
int main() {
	ll n,k;
	cin>>n>>k;
	for (ll i = 0; i < n; ++i)
	{
		ll x;cin>>x;
		v.push_back(x);
		DPright[x]++;
	}
	ll ans=0;
	for (ll i = 0; i < n; ++i)
	{
		int x=v[i];
		DPright[v[i]]-=1;
		if(x%k==0){
			if(DPleft.find(x/k)!=DPleft.end() && DPright.find(x*k)!=DPright.end()){
				ans+=DPleft[x/k]*DPright[x*k];
			}
		}
		DPleft[v[i]]+=1;
	}
	cout<<ans<<endl;
	return 0;
}