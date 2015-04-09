#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;
typedef long long ll;
typedef std::vector<int> vi;
std::vector<vi> v(26);
std::vector<ll> val(26);
std::vector<long long int> cum(111111,0);
int main() {

	for (ll i = 0; i < 26; ++i)
	{
		cin>>val[i];
	}
	string s;
	cin>>s;
	 ll cumu=0;
	for (ll i = 0; i < s.size(); ++i)
	{
		ll c=s[i]-'a';
		v[c].push_back(i+1);
		cumu+=val[c];
		cum[i+1]=cumu;
	}
	// for (ll i = 0; i <=s.size() ; ++i)
	// {
	// 	cout<<cum[i]<<" ";
	// }
	// cout<<endl;
	ll ans=0;
	for (ll i = 0; i < 26; ++i)
	{
		std::map<ll, ll> mymap;
		// cout<<"i "<<i<<" size "<<v[i].size()<<endl;
		for (ll j = 0; j < v[i].size(); ++j)
		{
			// cout<<"i "<<i<<" "<<v[i][j]<<endl;
			
			ll cumul=cum[v[i][j]-1];
			// cout<<" cumul "<<cumul<<endl;
			// cout<<"mymap[cumul] "<<mymap[cumul]<<endl; 
			ans+=mymap[cumul];
			// cout<<"cum[v[i][j]] "<<cum[v[i][j]]<<endl;
			if(mymap.find(cum[v[i][j]])==mymap.end())
				mymap[cum[v[i][j]]]=1;
			else
				mymap[cum[v[i][j]]]=mymap[cum[v[i][j]]]+1;
			// cout<<" mymap "<<mymap[cum[v[i][j]]]<<endl;
			// cout<<"ans "<<ans<<endl; 
		}
	}
	cout<<ans<<endl;
	return 0;
}