#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;


 long long int graph[2100][2100];
 long long int orig_graph[2100][2100];
 long long int flow[2100][2100];

long long int parent[2100];
bool visited[2100];

typedef std::vector<long long int> VLL;

#define INF 1000000000000

void initialize(long long int n){
	for(long long int i=0;i<n;i++){
		parent[i]=-1;visited[i]=0;
	}
}

std::vector<long long int> path;
vector<VLL>  adj(2100);
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
	long long int u,v,p,i;
	queue<long long int> myQ;
	myQ.push(s);
	visited[s]=1;
	while(!myQ.empty()){
		u=myQ.front();
		myQ.pop();
		p=adj[u].size();
		for(i=0;i<p;i++){
			v=adj[u][i];
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

 long long int max_flow(long long int n,long long int s,long long int t){
	 long long int cap;
	 long long int flow=0;
 	while(BFS(n,s,t)){
		path.clear();
		find_path(s,t);
		cap=limiting_capacity(s,t,n);
		flow+=cap;
		update_flow_graph(s,t,cap,n);
	}
	return flow;
}

void print_flow(long long int n){
	long long int i,j;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(flow[i][j]>0)
				cout<<i<<" "<<j<<endl;
		}
	}
}
// int main(){
// 	long long int u,v,w,n,res,k,i;
// 	cin>>n>>k;
// 	while(cin>>u>>v){
// 		graph[u][v]=1;
// 		orig_graph[u][v]=1;
// 		adj[u].push_back(v);
// 		adj[v].push_back(u);
// 	}

// 	for(i=0;i<k;i++){
// 		graph[n][i]=1;
// 		orig_graph[n][i]=1;
// 		adj[n].push_back(i);
// 		adj[i].push_back(n);
// 	}
// 	for(i=k;i<n;i++){
// 		graph[i][n+1]=1;
// 		orig_graph[i][n+1]=1;
// 		adj[i].push_back(n+1);
// 		adj[n+1].push_back(i);
// 	}
// 	max_flow(n+2,n,n+1);
// 	print_flow(n);
// 	return 0;
// }

int main(){
	int n,m,s,u,v,i,j;
	cin>>n>>m;
	for(i=0;i<n;i++){
		cin>>s;
		for(j=1;j<=s;j++){
			u=i;
			cin>>v;
			graph[u][n+v-1]=1;
			orig_graph[u][n+v-1]=1;
			adj[u].push_back(n+v-1);
			adj[n+v-1].push_back(u);
		}
	}
	
	for(i=0;i<n;i++){
		graph[m+n][i]=1;
		orig_graph[m+n][i]=1;
		adj[m+n].push_back(i);
		adj[i].push_back(m+n);
	}
	for(i=n;i<n+m;i++){
		graph[i][m+n+1]=1;
		orig_graph[i][m+n+1]=1;
		adj[i].push_back(m+n+1);
		adj[m+n+1].push_back(i);
	}
	long long ans=max_flow(m+n+2,m+n,m+n+1);
	cout<<ans<<endl;
	return 0;
}