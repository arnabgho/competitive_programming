#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;
typedef std::vector<int> vi;
std::vector<vi> G(100000);
std::vector<bool> visited(100000);

void dfs(int u){
	if(visited[u])
		return ;
	visited[u]=1;
	for (int i = 0; i < G[u].size(); ++i)
	{
		dfs(G[u][i]);
	}
}

int main() {
	int n,m;
	cout<<"Enter the number of edges\n";
	cin>>m;
	cout<<"Enter the graph\n";
	for (int i = 0; i <m ; ++i)
	{
		int u,v;
		cin>>u>>v;
		G[u].push_back(v);	
		G[v].push_back(u);		// Undirected edge If directed edge this would not be present
	}
	cout<<"Enter the start vertex\n";
	int s;
	cin>>s;
	dfs(s);
	return 0;
}