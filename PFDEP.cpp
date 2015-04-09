#include <stdio.h>
#include <iostream>
#include <stack>
#include <vector>
#include <stdlib.h>
#include <algorithm>
#include <queue>
using namespace std;

stack<int> mystack;
std::vector< vector <int> > adj(101);
std::vector< vector <int> > rev(101);

int visited[101];

void topological_sort(int u){
	if(visited[u])
		return;
	visited[u]=1;
	int size=adj[u].size();
	for(int v=0;v<size;v++){
		topological_sort(adj[u][v]);
	}
	mystack.push(u);
}

queue<int> result;

int invalid[101];
void remove_node(int node){
	invalid[node]=1;
	int u,pos;
	for(int v=0;v<adj[node].size();v++){
		u=adj[node][v];
		for(int i=0;i<rev[u].size();i++){
			if(rev[u][i]==node){
				pos=i;
				break;
			}
		}
		rev[u].erase(rev[u].begin()+pos);
	}
}

 void new_topological_sort(int n){
 	vector<int> L;
 	int new_int,num,node,v,i;
 	for(i=1;i<=n;i++){
 		if(rev[i].size()==0){
 			new_int=(int)malloc(sizeof(int));
 			new_int=i;
 			L.push_back(new_int);
 		}	
 	}
 	/*
 	cout<<"L: \n";
 	for(i=0;i<L.size();i++)	
 		cout<<L[i]<<" ";
 	cout<<endl;
	*/
 	num=0;
 	while(num<n){
 		node=L[0];
 		result.push(node);
 		num++;
 		remove_node(node);
 		L.erase(L.begin());
 		for(i=0;i<adj[node].size();i++){
 			v=adj[node][i];
 			if(rev[v].size()==0 && !invalid[v]){
  				new_int=(int)malloc(sizeof(int));
 				new_int=v;
 				L.push_back(new_int);				
 			}
 		}
 		sort(L.begin(),L.end());
 		/*
 		cout<<"L: \n";
 		for(i=0;i<L.size();i++)	
 			cout<<L[i]<<" ";
 		cout<<endl;*/
 	}
 	
 } 

int main(){
	int n,m,i,j,u,v,k;
	int new_edge,new_revedge;
	cin>>n>>m;
	for(i=1;i<=m;i++){
		cin>>v;
		cin>>k;
		for(j=1;j<=k;j++){
			cin>>u;
			new_edge=(int )malloc(sizeof(int));
			new_edge=v;
			adj[u].push_back(new_edge);

			new_revedge=(int )malloc(sizeof(int));
			new_revedge=u;
			rev[v].push_back(new_revedge);
		}
	}
	/*
	for(i=1;i<=n;i++){
		if(!visited[i])
			topological_sort(i);
	}

	while(!mystack.empty()){
		cout<<mystack.top()<<" ";
		mystack.pop();
	}
	*/
	new_topological_sort(n);
	while(!result.empty()){
		cout<<result.front()<<" ";
		result.pop();
	}

	cout<<endl;
	return 0;
}