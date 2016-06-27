#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;
typedef long long ll;
typedef pair<ll,ll> pl;
typedef pair<pl,ll> pll;
std::vector<pl> I;
std::vector<pl> B;
std::vector<pll> D;
std::vector<ll> ans(1111111,-1);
int main() {
	ll n,m;
	cin>>n>>m;
	for (int i = 0; i < n; ++i)
	{
		ll l,r;
		cin>>l>>r;
		I.push_back(pl(l,r));
	}
	for (int i = 0; i < m; ++i)
	{
		ll a;
		cin>>a;
		B.push_back(pl(a,i+1));
	}

	for (int i = 0; i+1 < n; ++i)
	{
		D.push_back(pll( pl(I[i+1].second-I[i].first,I[i+1].first-I[i].second) ,i ));
	}
	sort(B.rbegin(),B.rend());
	sort(D.rbegin(),D.rend());
	bool pos=1;
	int j=B.size()-1;
	for (int i = D.size()-1; i >=0  && j>=0; --i)
	{
		ll l=B[j].first;
		ll k=D[i].second;
		if(l>I[k+1].second-I[k].first || D[i].first.second>l )
			j--;
		else {
			ans[k]=B[j].second;
			j--;
		}
	}
	for (int i = 0; i < n-1; ++i)
	{
		if(ans[i]==-1)
			pos=0;
	}
	if(!pos)
		cout<<"No\n";
	else{
		cout<<"Yes\n";
		for (int i = 0; i < n-1; ++i)
		{
			cout<<ans[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}