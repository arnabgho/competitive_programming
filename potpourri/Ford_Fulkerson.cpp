#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <limits.h>
#include <queue>
#include <algorithm>
#include <string.h>

using namespace std;

bool visited[100];

int parent[100];

int residual_graph[100][100];
int graph[100][100];
//int graph[6][6];
#define INF 100000;
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

		cout<<"Path Flow :"<<path_flow<<endl;
	}	
	return max_flow;
}



int main()
{
    // Let us create a graph shown in the above example
   // graph[6][6] = { {0, 16, 13, 0, 0, 0},{0, 0, 10, 12, 0, 0},{0, 4, 0, 0, 14, 0},{0, 0, 9, 0, 0, 20},{0, 0, 0, 7, 0, 4},{0, 0, 0, 0, 0, 0}};
 	
	int n,i,j;
	cin>>n;
	cout<<"Enter the flow network :"<<endl;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++)
			cin>>graph[i][j];
	}

    cout << "The maximum possible flow is " << max_flow(0, n-1,n)<<endl;
 
    return 0;
}
