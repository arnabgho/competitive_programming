#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct Edge{
	int src,dest;
	int weight;
};

bool cmp(struct Edge  a,struct Edge b){
	return a.weight<b.weight;
}

struct Set{
	int parent,rank;
};

int Find_set(struct Set * vertices,int i){
	if(vertices[i].parent==i)
		return i;
	else{
		vertices[i].parent= Find_set(vertices,vertices[i].parent);
		return vertices[i].parent;
	}		
}

int Union(struct Set * vertices,int i,int j){
	int i_dash,j_dash;
	i_dash=Find_set(vertices,i);
	j_dash=Find_set(vertices,j);
	
	if(vertices[i_dash].rank<vertices[j_dash].rank)
		vertices[i_dash].parent=j_dash;
	else if(vertices[i_dash].rank>vertices[j_dash].rank)
		vertices[j_dash].parent=i_dash;
	else{
		vertices[i_dash].parent=j_dash;
		vertices[j_dash].rank++;
	}		
}	
int Make_set(struct Set * vertices,int n){
	int i;
	for(i=0;i<n;i++){
		vertices[i].parent=i;
		vertices[i].rank=0;
	}
}

vector<struct Edge> edges;
vector<struct Edge> A;
int m,u,v,i,n,src,dest,flag=1,ch,ch1;
int t,p,ans;
int weight,mst_weight=0;
struct Edge * new_edge;
struct Set * vertices;

int Kruskal(){
	vertices=(struct Set *)malloc(n*sizeof(struct Set));
	Make_set(vertices,n);
	
	sort(edges.begin(),edges.end(),cmp);
	for(i=0;i<edges.size();i++){
		//cout<<edges[i].weight<<endl;
		u=edges[i].src;
		v=edges[i].dest;
		if(Find_set(vertices,u)!=Find_set(vertices,v)){
			new_edge=(struct Edge *)malloc(sizeof(struct Edge));
			new_edge->src=u;
			new_edge->dest=v;
			new_edge->weight=edges[i].weight;
			mst_weight+=edges[i].weight;
			A.push_back(*new_edge);
			Union(vertices,u,v);
		}
	}
	free(vertices);
	return mst_weight;
}

int main(){
	cin>>t;
	while(t--){
		mst_weight=0;
		cin>>p>>n>>m;
		for(i=0;i<m;i++){
			cin>>src>>dest>>weight;
			new_edge=(struct Edge *)malloc(sizeof(struct Edge));
			new_edge->src=src-1;
			new_edge->dest=dest-1;
			new_edge->weight=weight;
			edges.push_back(*new_edge);
		}
		ans=Kruskal();
		cout<<p*ans<<endl;
		edges.clear();
		A.clear();
	}
	return 0;
}
