#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;
typedef std::vector<int> vi;
std::vector<vi> G(110);
std::vector<int> W;
void init(){
	for (int i = 0; i <110 ; ++i) G[i].clear();
}

int val=0;
int last=0;

void dfs(int u,int num){
	if(!G[u].size()){
		last=u;
		val=num;
		return ;
	}
	int maxim=0;
	int maxpos=0;
	for(auto v:G[u]){
		if(W[v]>maxim){
			maxim=W[v];
			maxpos=v;
		}
	}
	dfs(maxpos,maxim+num);
}

int main() {
	int t;
	cin>>t;
	for (int cas = 1; cas <=t ; ++cas)
	{
		int n,m;
		init();
		cin>>n>>m;
		for (int i = 0; i < n; ++i)
		{
			int x;cin>>x;W.push_back(x);
		}
		for (int i = 0; i < m; ++i)
		{
			int a,b;cin>>a>>b;
			G[a].push_back(b);
		}
		dfs(0,0);
		printf("Case %d: %d %d\n",cas,val,last );
	}
	return 0;
}