#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;
typedef std::vector<int> vi;
std::vector<vi> g(111111);
vector<bool> visited(111111,false);



int main() {
	int n,m,cost=0;
	cin>>n>>m;
	for (int i = 0; i < m; ++i)
	{
		int u,v;
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	for (int i = 1; i <= n; ++i)
	{
		if(visited[i])
			continue;
		int size=1;
		queue<int> myQ;
		myQ.push(i);
		visited[i]=true;
		while(!myQ.empty()){
			int u=myQ.front();
			myQ.pop();
			for (int j = 0; j < g[u].size(); ++j)
			{
				if(!visited[g[u][j]]){
					visited[g[u][j]]=true;
					size++;
					myQ.push(g[u][j]);
				}
			}
		}
		int k=sqrt(size);
		// cout<<"i "<<i<<" size "<<size<<endl;
		if(k*k==size){
			cost+=k;
		}
		else{
			cost+=k+1;
		}
	}
	cout<<cost<<endl;
	return 0;
}