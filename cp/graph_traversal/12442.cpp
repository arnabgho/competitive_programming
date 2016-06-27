#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;

set<int> cycle[51000];
std::vector<int> G(51000,0);
std::vector<int> sizes(51000,0);
std::vector<int> visited(51000,0);
map<int,int> belongCycle;
int n,cycleStart;

bool isCycle;

void Cycledfs(int u){
	//cout<<"u "<<u<<endl;
	if(visited[u]==2)
		return ;
	if(visited[u]==1){
		isCycle=1;
		cycleStart=u;
		return;
	}		
	visited[u]=1;
	
	Cycledfs(G[u]);
	
	visited[u]=2;
}

int main() {
	int t;
	cin>>t;
	for (int cas = 1; cas <=t; ++cas)
	{
		for(int i=0;i<51000;i++) cycle[i].clear();
		cin>>n;
		fill(G.begin(), G.end(),0);
		fill(sizes.begin(), sizes.end(),0);
		fill(visited.begin(), visited.end(),0);
		set<int> starts;
		for(int i=1;i<=n;i++) starts.insert(i);
		for (int i = 1; i <= n; ++i)
		{
			int u,v;
			cin>>u>>v;
			G[u]=v;
			if(starts.count(v))
				starts.erase(starts.find(v));
		}
		int numCycle=0;
		for (int i = 1; i <=n ; ++i)
		{
			if(!visited[i]){
				cycleStart=-1;
				Cycledfs(i);
				if(cycleStart==-1) continue;
				int cur=cycleStart;
				sizes[numCycle]=1;
				cycle[numCycle].insert(cur);
				belongCycle[cur]=numCycle;
				while(G[cur]!=cycleStart){
					cur=G[cur];
					belongCycle[cur]=numCycle;
					sizes[numCycle]++;
					cycle[numCycle].insert(cur);
				}
				numCycle++;
			}
		}
		int maxim=0;
		int ans=0;
		for(set<int>::iterator it=starts.begin();it!=starts.end();++it){
			int u=*it;
			int cur=0;
			while(!belongCycle.count(u)){
				cur++;
				u=G[u];
			}
			cur+=sizes[belongCycle[u]];
			if(cur>maxim){
				maxim=cur;
				ans=*it;
			}
		}
		if(starts.size()==0){
			for (int i = 0; i < numCycle; ++i)
			{
				if(sizes[i]>maxim){
					maxim=sizes[i];
					ans=*cycle[i].begin();
				}
			}
		}
		printf("Case %d: %d\n",cas,ans );
	}
	return 0;
}