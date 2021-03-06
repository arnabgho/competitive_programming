#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct Edge{
	int src,dest;
	double weight;
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
int main(){
	vector<struct Edge> edges;
	vector<struct Edge> A;
	int u,v,i,n,src,dest,flag=1,ch,ch1;
	double weight,mst_weight=0;
	struct Edge * new_edge;
	struct Set * vertices;
	cin>>n;
	/*
	while(!(flag==0))
	{
		ch=getchar();
		ch1=ch;
		//cout<<"ch1="<<ch1<<endl;
		if(ch==-1)
		{	
			flag=0;
			break;
		}
		else
			ungetc(ch,stdin);
		if(ch1!=-1){
			scanf("%d %d %lf\n",&src,&dest,&weight);
			//cout<<src<<endl<<dest<<endl<<weight<<endl;
			cout<<endl;
			}
		if(ch1!=-1){
			new_edge=(struct Edge *)malloc(sizeof(struct Edge));
			new_edge->src=src;
			new_edge->dest=dest;
			new_edge->weight=weight;
			edges.push_back(*new_edge);
		}
			
		else
			break;
	}*/
	while(cin>>src>>dest>>weight){
		new_edge=(struct Edge *)malloc(sizeof(struct Edge));
		new_edge->src=src;
		new_edge->dest=dest;
		new_edge->weight=weight;
		edges.push_back(*new_edge);
	}	
	
	//Kruskal's Algorithm begins
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
	sort(A.begin(),A.end(),cmp);
	printf("%.2lf\n",mst_weight);
	for(i=0;i<A.size();i++){
	if(A[i].src<A[i].dest)	
		printf("%d %d %.2lf\n",A[i].src,A[i].dest,A[i].weight);
	else
		printf("%d %d %.2lf\n",A[i].dest,A[i].src,A[i].weight);	
	}	
	
	return 0;
}
