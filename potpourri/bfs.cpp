#include <stdio.h>
#include <queue>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct ob{
	int dest,weight;
};

int parent[10000];
bool visited[10000];

void initialize(){
	for(int i=0;i<10000;i++){
		parent[i]=-1;visited[i]=0;
	}
}

void printPath(int s,int t){
	if(s==t)
		cout<<t<<endl;
	else{
		printPath(s,parent[t]);
		cout<<t<<endl;
	}
}

bool existPath(int s,int t){
	if(s==t)	return true;
	else if(parent[t]!=-1) return existPath(s,parent[t]);
	return false;
}

void BFS(vector<vector<struct ob *> > &adj,int n,int s,int t){
	//cout<<"n: "<<n<<endl;
	int u,v,p;
	queue<int> myQ;
	int i;
	myQ.push(s);
	visited[s]=1;
	while(!myQ.empty()){
		u=myQ.front();
		myQ.pop();
		p=adj[u].size();
		for(i=0;i<p;i++){
			v=adj[u][i]->dest;
			if(!visited[v]){
				myQ.push(v);
				parent[v]=u;
				visited[v]=1;
			}
		}
	}
	//sort(tree.begin(),tree.end(),cmp);
	
	/*
	for(i=0;i<n;i++){
		if(tree[i]->weight!=-1)
			cout<<tree[i]->dest<<" "<<tree[i]->weight<<endl;
	}*/

	//for(int i=0;i<n;i++) cout<<parent[i]<<endl;
	//cout<<"Parent\n";	
	if(visited[t])
		printPath(s,t);
	else{
		//while(1);
		cout<<"-1"<<endl;
	}
}	

int main(){
	initialize();
	int n,u,v,weight,s,t;
	struct ob *newob;
	cin>>n;
	vector<vector<struct ob *> > adj(n);
	cin>>s>>t;
	while(cin>>u>>v){
		newob=(struct ob *)malloc(sizeof(struct ob));
		newob->dest=v;
		newob->weight=1;
		adj[u].push_back(newob);
	}	

	BFS(adj,n,s,t);

	return 0;
}