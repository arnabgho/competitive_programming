#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;
typedef long long ll;
typedef pair<int,int> pi;
std::vector<double> l,sz(111111);
std::vector<std::vector<pi> > g(111111);
std::vector<long long> edges(111111);
long long int n,q,x,y;
void dfs(ll v,ll pr){
	sz[v]=1.0;
	for (int i = 0; i < g[v].size(); ++i)
	{
		int u=g[v][i].first;
		if(u==pr)
			continue;
		dfs(u,v);
		sz[v]+=sz[u];
		edges[g[v][i].second]=sz[u]*(n-sz[u]);
	}
}

int main() {
	double n_ref,z;
	cin>>n;
	n_ref=n;
	l.push_back(0);
	for (ll i = 1; i < n; ++i)
	{
		cin>>x>>y>>z;
		l.push_back(z);
		g[x].push_back(make_pair(y,i));
		g[y].push_back(make_pair(x,i));
	}
	dfs(1,-1);
	cin>>q;
	double sum=0;
	for (int i = 1; i < n; ++i)
	{
		sum+=l[i]*edges[i];
	}
	// cout<<"sum "<<sum<<endl;
	for (ll i = 0; i < q; ++i)
	{
		int r;
		double w;
		cin>>r>>w;
		double d=l[r]-w;
		l[r]=w;
		sum-=d*edges[r];
		std::cout.setf( std::ios::fixed, std:: ios::floatfield ); 
		double res=(6.0*sum)/(n_ref*(n_ref-1));
		cout<<res<<endl;
	}
	return 0;
}