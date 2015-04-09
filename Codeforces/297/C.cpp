#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;
typedef long long ll;
set<ll> pos;
std::vector<ll> v;
std::vector<ll> p;
int main() {
	ll n;
	cin>>n;
	for (int i = 0; i < n; ++i)
	{
		ll x;
		cin>>x;
		v.push_back(x);
	}
	sort(v.rbegin(),v.rend());
	for (int i = 0; i <n-1; ++i)
	{
		if(v[i]-v[i+1]<=1){
			p.push_back(min(v[i],v[i+1]));
			i++;
		}
	}
	ll ans=0;
	sort(p.rbegin(),p.rend());
	for (int i = 0; i +1 < p.size();i+=2)
	{
		ans+=p[i]*p[i+1];
	}
	cout<<ans<<endl;
	return 0;
}