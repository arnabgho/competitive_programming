#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;
typedef std::vector<int> vi;
std::vector<vi> graph(240000);
std::vector<vi> sub(7,vi(240000,0));

int dfs(int u,int val){
	if(sub[val][u])
		return sub[val][u];
	int sum=val;
	for (int i = 0; i < graph[u].size(); ++i)
	{
		int cost=1e9;
		for (int j = 1; j<4; ++j)
		{
			if(j==val)
				continue;
			dfs(graph[u][i],j);
			cost=min(cost,sub[j][graph[u][i]]);
		}
		sum+=cost;
	}
	sub[val][u]=sum;
	return sum;
}


int main() {
	int t;
	cin>>t;
	for (int cas = 1; cas <=t ; ++cas)
	{
		cout<<"Case "<<cas<<endl;
		for (int i = 0; i < 4; ++i)
		{
			fill(sub[i].begin(),sub[i].end(),0);
		}
		int n;
		cin>>n;
		for (int i = 0; i <=n ; ++i)
		{
			graph[i].clear();
		}
		for (int i = 1; i <= n; ++i)
		{
			int p;
			cin>>p;
			graph[p].push_back(i);
		}
		int ans=1e9;
		// cout<<"Hi \n";
		if(cas==4)
			continue;
		for (int i = 1; i <4 ; ++i)
		{
			if(cas==4)
				cout<<"i "<<i<<endl;
			ans=min(ans,dfs(1,i));
		}
		cout<<"Case #"<<cas<<": "<<ans<<endl;
	}
	return 0;
}