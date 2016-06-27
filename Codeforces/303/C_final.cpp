#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;
typedef long long ll;
std::vector<ll> x,h;
std::vector<ll> v(111111,0);
int main() {
	ll n;
	cin>>n;
	for (ll i = 0; i < n; ++i)
	{
		ll a,b;
		cin>>a>>b;
		x.push_back(a);
		h.push_back(b);
	}
	ll ans=0;
	ll pos=-1e12;
	for (ll i = 0; i <n ; ++i)
	{
		if(x[i]-h[i]>pos){
			pos=x[i];ans++;continue;
		}
		if(i==n-1 || x[i]+h[i]<x[i+1]){
			pos=x[i]+h[i];ans++;continue;
		}
		pos=x[i];
	}
	cout<<ans<<endl;
	return 0;
}