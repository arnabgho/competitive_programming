#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pl;
typedef pair<double,pl> pdl;
std::vector<pdl> all;
std::vector<int> res(330000);
int main() {
	ll n,w;
	cin>>n>>w;
	for (int i = 0; i < n; ++i)
	{
		ll x,y;
		cin>>x>>y;
		pl p1=pl(i,1);
		pl p2=pl(i,2);
		all.push_back( pdl(x,p1));
		all.push_back( pdl(1.0*y/2.0,p2));
	}
	sort(all.begin(),all.end());
	std::vector<bool> used(n+1);
	fill(used.begin(),used.end(),0);
	ll rem=w;
	ll t=0;
	for (int i = 0; i < all.size(); ++i)
	{	
		pdl pd=all[i];
		pl p=pd.second;
		if(used[p.first]) continue;
		if(rem<=0) break;
		if(rem>=2){
			rem-=p.second;
			t+=p.second*pd.first;
			res[p.first]=p.second;
			used[p.first]=1;
		}	
		else if(rem==1){
			ll min=1e9;
			ll minpos=i;
			for (int j = i; j <all.size() ; ++j)
			{
				if(!used[all[j].second.first] && all[j].first*all[j].second.second<min){
					min=all[j].first*all[j].second.first;
					minpos=j;
				}
			}
			rem-=all[minpos].second.second;
			t+=all[minpos].first*all[minpos].second.second;
			res[all[minpos].second.first]=all[minpos].second.second;
		}
	}
	cout<<t<<endl;
	for (int i = 0; i < n; ++i)
	{
		cout<<res[i];
	}
	cout<<endl;
	return 0;
}