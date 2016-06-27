#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;
typedef long long ll;
typedef pair<ll,ll> pi;
const double eps=1e-9;
double PI = 3.1415926535897932384;
int main() {
	ll t;
	cin>>t;
	for (ll cas = 1; cas <= t; ++cas)
	{
		double v,d,g;
		g=9.8;
		cin>>v>>d;
		double val=(g*d)/(v*v);
		// cout<<"val "<<val<<endl;
		double ans=asin (val) * 90.0 / PI;
		printf("Case #%lld: %.7lf\n",cas,ans );
	}
	return 0;
}