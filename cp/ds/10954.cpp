#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;
typedef long long ll;

std::priority_queue<ll, std::vector<ll>, std::greater<ll> > pq;
int main() {
	ll n;
	cin>>n;
	while(n>0){
		while(pq.size()) pq.pop();
		for (int i = 0; i < n; ++i)
		{
			ll x;
			cin>>x;
			pq.push(x);
		}
		ll ans=0;
		while(pq.size()!=1){
			ll a=pq.top();pq.pop();
			ll b=pq.top();pq.pop();
			ans+=(a+b);
			pq.push(a+b);
		}
		cout<<ans<<endl;
		cin>>n;
	}
	return 0;
}