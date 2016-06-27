#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;
typedef long long ll;
typedef pair<ll,ll> pi;
typedef std::vector<pi> vp;
const ll MAXM=100000LL;
const ll MOD=1000000007LL;
const ll DIV=(long long) 5e8 + 4;
std::vector<vp> v(MAXM+10);
std::vector<ll> subtree(MAXM+10,0);
std::vector<ll> path(MAXM+10,0);
void dfs(int p,int u){
	ll sum=0;
	ll val=0;
	ll ret=0;
	for(int i=0;i<v[u].size();i++){
		if(v[u][i].first==p)
			continue;
		dfs(u,v[u][i].first);
		ll w=v[u][i].second;
		ll temp=(path[v[u][i].first]+1LL)*w;
		sum+=temp;
		sum%=MOD;
		val+=temp*temp;
		val%=MOD;
		ret+=subtree[v[u][i].first];
		ret%=MOD;
	}

	ret+=sum;
	ret%=MOD;
	ret+=(((sum*sum-val)%MOD)*DIV)%MOD;
	// cout<<" p "<<p<<" u "<<u<<" sum "<<sum<<" val "<<val<<endl;
	subtree[u]=ret%MOD;
	path[u]=sum%MOD;
}


int main() {
	int n;
	cin>>n;
	for (int i = 1; i < n; ++i)
	{
		ll a,b,w;
		cin>>a>>b>>w;
		v[a].push_back(make_pair(b,w));
		v[b].push_back(make_pair(a,w));
	}
	dfs(-1,1);
	cout<<subtree[1]<<endl;
	return 0;
}