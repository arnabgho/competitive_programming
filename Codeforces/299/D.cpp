#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;
typedef long long ll;
const ll mod=1e9+7;
std::vector<ll> v;
ll modulo(ll n){
	if(n>mod){
		return n%mod;
	}
	return n;
}
int main() {
	ll n,m;
	cin>>n>>m;
	string p;
	cin>>p;
	for (ll i = 0; i < m; ++i)
	{
		ll x;cin>>x;v.push_back(x-1);
	}
	string res="";
	for (ll i = 0; i < n; ++i)
	{
		res+='-';
	}
	ll nEmpty=n;
	bool pos=1;
	for (ll i = 0; i < v.size() && pos; ++i)
	{
		ll k=v[i];
		for (ll j = 0; j <p.size() && pos ; ++j)
		{
			if(res[k]=='-'){
				res[k]=p[j];
				nEmpty--;
			}
			else if(res[k]!=p[j])
				pos=0;
			k++;
		}
	}
	if(!pos) {cout<<"0\n";return 0;}
	ll ans=1;
	for (ll i = 0; i <nEmpty; ++i)
	{
		ans=modulo(ans*26);
	}
	cout<<ans<<endl;
	return 0;
}