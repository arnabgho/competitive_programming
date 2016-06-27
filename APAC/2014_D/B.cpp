#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;
typedef long long ll;
typedef pair<ll,ll> PII;
#define fi first
#define se second
const double eps=1e-9;
std::vector<PII> BUS(600);
std::vector<int> num(6000);
int main() {
	ll t;
	cin>>t;
	for (ll cas = 1; cas <= t; ++cas)
	{
		ll n;
		cin>>n;
		for (int i = 0; i < n; ++i)
		{
			cin>>BUS[i].fi>>BUS[i].se;
			num[BUS[i].fi]++;
			num[BUS[i].se+1]--;
		}
		std::vector<int> cum(6000);
		for (int i = 1; i <6000 ; ++i)
		{
			cum[i]=cum[i-1]+num[i];
		}
		fill(num.begin(),num.end(),0);
		int P;
		cin>>P;
		printf("Case #%lld: ",cas);
		for (int i = 0; i < P; ++i)
		{
			int x;
			cin>>x;
			cout<<cum[x]<<" ";
		}
		cout<<endl;
		ll ans=0;
		
	}
	return 0;
}