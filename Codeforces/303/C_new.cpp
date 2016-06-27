#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;
typedef long long ll;
typedef pair<ll,ll> pi;
// std::vector<ll> x(111111);
// std::vector<ll> h(111111);
ll x[111111];
ll h[111111];
std::vector<pi> t;
int main() {
	ll n;
	cin>>n;
	for (ll i = 0; i < n; ++i)
	{
		cin>>x[i]>>h[i];
	}
	for (ll i = 0; i < n; ++i)
	{
		if(i>0 && (x[i]-x[i-1]>h[i]))
			t.push_back(pi(x[i]-h[i],x[i]) );
		else if(i==0 )
			t.push_back(pi(x[i]-h[i],x[i]));
		if(i<n-1 && (x[i+1]-x[i]>h[i]))
			t.push_back(pi(x[i],x[i]+h[i]) );
		else if(i==n-1 )
			t.push_back( pi(x[i],x[i]+h[i]));
	}
	// cout<<"HI\n";
	sort(t.begin(),t.end());
	ll last=t[0].second;
	ll ans=1;
	for (ll i = 1; i < n ; ++i)
	{
		if(t[i].first>last){
			ans++;
			last=t[i].second;
		}
	}
	cout<<ans<<endl;
	return 0;	
}