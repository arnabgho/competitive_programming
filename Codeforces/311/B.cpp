#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;
typedef long long ll;
std::vector<ll> a;
int main() {
	ll n,w;
	cin>>n>>w;
	for (ll i = 0; i < 2*n; ++i)
	{
		ll x;
		cin>>x;
		a.push_back(x);
	}
	sort(a.begin(),a.end());
	double ans=0;
	//case 1
	double x=a[0],y=a[n];
	if(y>=2*x && w>=3*n*x)
		ans=3*n*x;
	if(x>=y/2 && w>=1.5*n*y)
		ans=max(ans,1.5*n*y);
	if(x>=1.0*w/(3.0*n) && y>=2.0*w/(3.0*n))
		ans=max(ans,1.0*w);
	// cout<<ans<<endl;
	printf("%.7lf\n",ans);
	return 0;
}