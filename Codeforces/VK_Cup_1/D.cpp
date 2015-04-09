#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;
typedef long long ll;
// std::priority_queue<ll, std::vector<ll>, std::greater<ll> > pq;
set<ll> pq;
std::vector<ll> t;
int main() {
	ll n,M,T;
	cin>>n>>M>>T;
	for (ll i = 0; i < n; ++i)
	{
		int h,m,s;
		scanf("%d:%d:%d",&h,&m,&s);
		t.push_back(3600LL*h+60*m+s);
	}
	ll R=1;
	bool pos=1;
	bool foundM=0;
	vector<ll> res;
	pq.insert(t[0]);
	res.push_back(1);
	ll cur=1;
	ll i=1;
	for(ll c=0;c<86400;c++){
		while(!pq.empty() && c-*pq.begin()>=T)
			pq.erase(pq.begin());
		while(i<n && c==t[i]){
			if(pq.size()<M){
				pq.insert(t[i]);
				cur++;R++;
				res.push_back(cur);
			}
			else if(pq.size()==M){
				pq.erase(*pq.rbegin());
				res.push_back(cur);
				pq.insert(t[i]);
			}
			i++;
		}
		// if(i>=n) break;
		if(pq.size()>=M)
			foundM=1;
	}
	if(!foundM)
		cout<<"No solution" <<endl;
	else{
		cout<<R<<endl;
		for (ll i = 0; i < res.size(); ++i)
		{
			cout<<res[i]<<endl;
		}
	}
	return 0;
}