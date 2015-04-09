#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pl;
std::vector<pl> v;
ll n,k;

ll check(ll x){
	ll ans=1e9;
	for (int i = 0; i < v.size(); ++i)
	{
		if(v[i].first==x)
			ans=min(ans,v[i].second);
	}
	ll left=0;
	ll right=v.size()-1;
	while(left<right){
		// cout<<"left "<<left<<" right "<<right<<endl;
		// cout<<v[left].first<<" "<<v[left].second<<endl;
		// cout<<v[right].first<<" "<<v[right].second<<endl;
		if(v[left].first+v[right].first==x){
			if(v[left].second+v[right].second<=k)
				ans=min(ans,v[left].second+v[right].second);
			right--;
			continue;
		}
		else if(v[left].first+v[right].first>x){
			right--;
		}
		else if(v[left].first+v[right].first<x)
			left++;
	}
	if(ans==1e9) return -1;
	else return ans;
}

int main() {
	cin>>n>>k;
	for (int i = 0; i < n; ++i)
	{
		ll x;
		cin>>x;
		for (int j = 1; j <=k ; ++j)
		{
			v.push_back(pl(x*j,j));
		}
	}
	sort(v.begin(),v.end());
	ll q;
	cin>>q;
	for (int i = 0; i < q; ++i)
	{
		ll x;
		cin>>x;
		cout<<check(x)<<endl;
	}
	return 0;
}