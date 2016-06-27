#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;
typedef std::vector<int> vi;
typedef std::vector<vi> vvi;
vector<bool> cUsed(111,false);
std::vector<bool> visited(111,false);
std::vector<vvi> g(111,vvi(111));

void dfs(int c,int u){
	if(visited[u])
		return;
	visited[u]=1;
	for (int i = 0; i <g[c][u].size() ; ++i)
	{
		int v=g[c][u][i];
		dfs(c,v);
	}
}

int main() {
	int n,m,q;
	cin>>n>>m;
	for (int i = 0; i < m; ++i)
	{
		int a,b,c;
		cin>>a>>b>>c;
		cUsed[c]=1;
		g[c][a].push_back(b);
		g[c][b].push_back(a);
	}
	cin>>q;
	for (int i = 0; i < q; ++i)
	{
		int u,v,ans=0;
		cin>>u>>v;
		for (int c = 1; c <=100 ; ++c)
		{
			if(!cUsed[c]) continue;
			// cout<<"c "<<c<<endl;
			fill(visited.begin(),visited.end(),0);
			dfs(c,u);
			if(visited[v]){
				// cout<<"c "<<c<<endl;
				ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}