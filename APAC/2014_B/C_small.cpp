#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;
typedef long long ll;
typedef pair<ll,ll> pi;
const double eps=1e-9;
map<int,int> DP;
int main() {
	ll t;
	cin>>t;
	for (ll cas = 1; cas <= t; ++cas)
	{
		DP.clear();
		int n,k;
		cin>>n>>k;
		std::vector<int> v;
		for (int i = 0; i < n; ++i)
		{
			int x;cin>>x;
			v.push_back(x);
		}
		bool pos=1;
		int iter=0;
		while(pos && v.size()>=3){
			iter++;
			std::vector<int> temp;
			pos=0;
			int position=-1;
			for (int i = 1; i+1 <v.size() ; i++)
			{
				if(v[i-1]==v[i]-k && v[i]+k==v[i+1]) {
					position=i;
					pos=1;
				}
			}
			if(!pos) break;
			if(position!=-1){
				// cout<<"position "<<position<<endl;
				for(int i=0;i<v.size();i++){
					if(i==position-1 || i==position || i==position+1) continue;
					temp.push_back(v[i]);
				}
			}
			// for(auto x:temp) cout<<x<<" ";
			// cout<<endl;	
			v=temp;
		}
		int ans=v.size();
		printf("Case #%lld: %d\n",cas,ans);
	}
	return 0;
}