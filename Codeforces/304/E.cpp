#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <limits.h>
#include <queue>
#include <algorithm>
#include <string.h>

using namespace std;

const int MAXN=300;
bool visited[MAXN];

int parent[MAXN];

int residual_graph[MAXN][MAXN];
int graph[MAXN][MAXN];
//int graph[6][6];
#define INF 10000000
bool bfs(int s,int t,int n){
	queue<int> myQ;
	int u,v,i;
	memset(visited,false,sizeof(visited));
	//memset(parent,0,sizeof(parent));
	parent[s]=-1;
	myQ.push(s);
	visited[s]=1;
	while(!myQ.empty()){
		u=myQ.front();
		myQ.pop();
		visited[u]=1;
		for(i=0;i<n;i++){
			if(!visited[i] && residual_graph[u][i]>0 ){
				myQ.push(i);
				parent[i]=u;
			}
		}
	}
	return visited[t];
}

int max_flow(int s,int t,int n){
	int u,v,i,j;
	int path_flow,max_flow=0;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++)
			residual_graph[i][j]=graph[i][j];
	}


	while(bfs(s,t,n)){
		v=t;
		path_flow=INF;
		while(v!=s){
			u=parent[v];
			path_flow=min(path_flow,residual_graph[u][v]);
			v=u;
		}
		v=t;
		while(v!=s){
			u=parent[v];
			//path_flow=min(path_flow,residual_graph[u][v]);
			residual_graph[u][v]-=path_flow;
			residual_graph[v][u]+=path_flow;
			v=u;
		}
		max_flow+=path_flow;

		// cout<<"Path Flow :"<<path_flow<<endl;
	}	
	return max_flow;
}


std::vector<int> a(MAXN);
std::vector<int> b(MAXN);
int main()
{
    // Let us create a graph shown in the above example
   // graph[6][6] = { {0, 16, 13, 0, 0, 0},{0, 0, 10, 12, 0, 0},{0, 4, 0, 0, 14, 0},{0, 0, 9, 0, 0, 20},{0, 0, 0, 7, 0, 4},{0, 0, 0, 0, 0, 0}};
 	
	// int n,i,j;
	// cin>>n;
	// cout<<"Enter the flow network :"<<endl;
	// for(i=0;i<n;i++){
	// 	for(j=0;j<n;j++)
	// 		cin>>graph[i][j];
	// }


	int n,m;
	cin>>n>>m;
	int s=0;
	int t=2*n+1;
	int sA=0,sB=0;
	for (int i = 1; i <= n; ++i)
	{
		cin>>a[i];
		graph[s][i]=a[i];
		sA+=a[i];
	}

	for (int i = 1; i <=n ; ++i)
	{
		cin>>b[i];
		graph[n+i][t]=b[i];
		sB+=b[i];
	}
	for (int i = 1; i <=n ; ++i)
	{
		graph[i][n+i]=INF;
	}
	for (int i = 0; i < m; ++i)
	{
		int x,y;
		cin>>x>>y;
		graph[x][n+y]=INF;
		graph[y][n+x]=INF;
	}
	int Mflow=max_flow(s,t,2*n+2);
    // cout << "The maximum possible flow is " << Mflow<<endl;
 	if(sA!=sB || Mflow!=sA)
 		cout<<"NO\n";
 	else{
 		cout<<"YES\n";
 		for (int i = 1; i <=n ; ++i)
 		{
 			for (int j = 1; j <=n ; ++j)
 			{
 				if(residual_graph[i][n+j]==INF || residual_graph[i][n+j]==0)
 					cout<<"0 ";
 				else
 					cout<< (INF-residual_graph[i][n+j] )<<" ";
 			}
 			cout<<endl;
 		}
 	}

    return 0;
}
