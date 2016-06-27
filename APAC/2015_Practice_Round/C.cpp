#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;
typedef long long ll;
typedef pair<ll,ll> pi;
const double eps=1e-9;
std::vector<string> v;
int main() {
	ll t;
	cin>>t;
	for (ll cas = 1; cas <= t; ++cas)
	{
		v.clear();
		int n;
		cin>>n;
		scanf("\n");
		string s1,s2,s;
		for (int i = 0; i < n; ++i)
		{
			// cin>>s1>>s2;
			// s=s1+ " "+s2;
			getline(cin,s);
			v.push_back(s);
		}
		// for(auto x:v) cout<<x<<endl;
		int prev=0;
		int cur=1;
		int ans=0;
		while(cur<n){
			if(std::lexicographical_compare(v[cur].begin(),v[cur].end(),v[prev].begin(),v[prev].end())){
				ans++;
			}
			else{
				prev=cur;
			}
			cur++;
		}
		printf("Case #%lld: %d\n",cas,ans );
	}
	return 0;
}