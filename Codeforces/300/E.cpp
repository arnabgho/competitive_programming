#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;
typedef std::vector<int> vi;
const int MAXN = 210000;
std::vector<vi> e(MAXN);
int w[MAXN];
int dpmax[MAXN];
int dpmin[MAXN];

void dfs(int v){
	if(e[v].size()==0){
		w[v]=1;
		dpmax[v]=dpmin[v]=0;
		return ;
	}
	int md=1e9,s=0;
	w[v]=0;
	for (int u:e[v])
	{
		dfs(u);
		w[v]+=w[u];
		md=min(md,dpmin[u]);
		s+=w[u]-dpmax[u];
	}
	dpmax[v]=w[v]-md-1;
	dpmin[v]=s-1;
}


int main() {
	int n;
	cin>>n;
	for (int i = 0; i < n-1; ++i)
	{
		int u,v;
		cin>>u>>v;u--;v--;
		e[u].push_back(v);
	}
	dfs(0);
	cout<<dpmax[0]+1<<" "<<dpmin[0]+1<<endl;
	return 0;
}