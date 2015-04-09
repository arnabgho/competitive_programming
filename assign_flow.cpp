#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <queue>
#include <algorithm>

using namespace std;

 long long int graph[400][400];
 long long int orig_graph[400][400];
 long long int flow[400][400];

long long int parent[400];
bool visited[400];

#define INF 1000000000000

void initialize(long long int n){
	for(long long int i=0;i<n;i++){
		parent[i]=-1;visited[i]=0;
	}
}

std::vector<long long int> path;

void find_path(long long int s,long long int t){
	if(s==t) path.push_back(t);

	else{
		find_path(s,parent[t]);
		path.push_back(t);
	}
}

bool BFS(long long int n,long long int s,long long int t){
	//cout<<"n: "<<n<<endl;
	initialize(n);
	long long int u,v,p;
	queue<long long int> myQ;
	myQ.push(s);
	visited[s]=1;
	while(!myQ.empty()){
		u=myQ.front();
		myQ.pop();
		p=n;
		for(v=0;v<p;v++){
			//v=adj[u][i]->dest;
			//if(graph[u][v]==0) continue;
			if(!visited[v] && graph[u][v]>0){
				myQ.push(v);
				parent[v]=u;
				visited[v]=1;
			}
		}
	}
	if(!visited[t]) return false;
	else return true;
}

 long long int limiting_capacity(long long int s,long long int t,long long int n){
	long long int i,u,v,minim=INF;
	long long int k=path.size();
	for(i=0;i<k-1;i++){
		u=path[i];
		v=path[i+1];
		minim=min(minim,graph[u][v]);
	}
	return minim;
}

void update_flow_graph(long long int s,long long int t,long long int cap,long long int n){
	long long int i,u,v;
	long long int k=path.size();
	for(i=0;i<k-1;i++){
		u=path[i];
		v=path[i+1];
		graph[u][v]-=cap;
		graph[v][u]+=cap;
		if(orig_graph[u][v]>0)
			flow[u][v]+=cap;
		else
			flow[v][u]-=cap;
	}
}

 long long int max_flow(long long int n){
	 long long int cap;
	 long long int flow=0;
 	while(BFS(n,0,n-1)){
		path.clear();
		find_path(0,n-1);
		cap=limiting_capacity(0,n-1,n);
		flow+=cap;
		update_flow_graph(0,n-1,cap,n);
	}
	return flow;
}

void print_flow(long long int n){
	long long int i,j;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(flow[i][j]>0)
				cout<<i<<" "<<j<<" "<<flow[i][j]<<endl;
		}
	}
}
int main(){
	 long long int u,v,w,n,res;
	cin>>n;
	while(cin>>u>>v>>w){
		graph[u][v]+=w;
		orig_graph[u][v]+=w;
	}
	res=max_flow(n);
	cout<<res<<endl;
	print_flow(n);
	return 0;
}