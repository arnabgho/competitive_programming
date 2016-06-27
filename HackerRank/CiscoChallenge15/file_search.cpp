#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;

typedef long long ll;
map<ll,ll> files[310];
int main() {
	ll n,m,q,t,k;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>m;
		for (int j = 0; j < m; ++j)
		{
			ll x;
			cin>>x;
			files[i][x]++;
		}
	}
	map<ll,ll> cur;
	cin>>q;
	while(q--){
		cin>>t>>k;
		cur.clear();
		ll ans=0;
		for (int i = 0; i < k; ++i){ll x;cin>>x;cur[x]++;}
		if(t==1){
			for(int i=1;i<=n;i++){
				bool pos=1;
				for(map<ll,ll>::iterator it=cur.begin();it != cur.end();++it){
					if(files[i][it->first]<it->second)
						pos=0;
				}
				ans+=pos;
			}	
		}	
		else if(t==2){
			for(int i=1;i<=n;i++){
				bool pos=0;
				for(map<ll,ll>::iterator it=cur.begin();it != cur.end();++it){
					if(files[i].find(it->first)!=files[i].end())
						pos=1;
				}
				ans+=pos;
			}
		}
		else if(t==3){
			for(int i=1;i<=n;i++){
				bool pos=1;
				ll nfound=0;
				for(map<ll,ll>::iterator it=cur.begin();it != cur.end();++it){
					nfound+=min(it->second,files[i][it->first]);
				}
				ans+= (nfound>0 && nfound<k);
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}