#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;
typedef long long int ll;
typedef pair<ll,ll> pl;
map<pl,ll> cnt;

ll fact[20];

void f(){
	fact[0]=1;
	for (ll i = 1; i <=20 ; ++i)
	{
		fact[i]=i*fact[i-1];
	}
}

std::vector<pl> generate(std::vector<ll> v){
	ll val=1;
	ll n=v.size();
	for (ll i = 0; i <n ; ++i)
		val*=3LL;
	std::vector<pl> res;
	for (ll mask = 0; mask < val; ++mask)
	{
		ll ovflow=0;
		ll bits=0;
		ll qm=mask;
		ll s=0;
		for (ll i = 0; i < n; ++i)
		{
			if(qm%3==0){
				bits++;
				if(v[i]>20)
					ovflow=1;
				else
					s+=fact[v[i]];
				if(s>1e17)
					ovflow=1;
			}
			else if(qm%3==1){
				s+=v[i];
				if(s>1e17)
					ovflow=1;
			}
			qm/=3LL;
		}
		if(ovflow==0)
			res.push_back(pl(s,bits));
	}
	return res;
}

int main() {
	f();
	std::vector<ll> v1,v2;
	vector<pl> V1,V2;
	ll n,k,s;
	cin>>n>>k>>s;
	for (ll i = 0; i < n/2; ++i)
	{
		ll x;cin>>x;v1.push_back(x);
	}
	for (ll i = n/2; i < n; ++i)
	{
		ll x;cin>>x;v2.push_back(x);
	}
	V1=generate(v1);
	V2=generate(v2);
	for (ll i = 0; i < V2.size(); ++i)
	{
		cnt[V2[i]]++;
		// cout<<V2[i].first<<" "<<V2[i].second<<endl;	
	}
	ll ans=0;
	for (ll i = 0; i < V1.size(); ++i)
	{
		ll curS=V1[i].first;
		ll curK=V1[i].second;

		ll reqS=s-curS;
		ll reqK=k-curK;
		if(reqK<0) continue;
		for (ll j = 0; j <= reqK; ++j)
		{
			ans+=cnt[pl(reqS,j)];
		}
	}
	cout<<ans<<endl;
	return 0;
}