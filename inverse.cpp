#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;
/*
int **arr[2001][2001];
int **visited[2000];
int **tree[2001][2001];
int **ans[2001][2001];
*/

int **arr;
int *visited;
int **tree;
int **ans;
void dfs(int start,int u,int n){
	int v;
	if(visited[u])
		return;

	//cout<<"Start:"<<start<<" u :"<<u<<endl;
	visited[u]=1;
	for(v=0;v<n;v++){
		if(v==start)
			continue;
		else if(tree[u][v]>0 && !visited[v]){
				//cout<<"u "<<u<<" v "<<v<<endl;
				ans[start][v]=ans[start][u]+tree[u][v];
			//ans[v][start]=ans[start][u]+tree[u][v];
			//cout<<"Inside Update\n";
			dfs(start,v,n);
		}	
	}
}

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
int main(){
	vector<struct Edge> edges;
	vector<struct Edge> A;
	int u,v,i,n,src,dest,flag=1,ch,ch1;
	//double weight;
	struct Edge * new_edge;
	struct Set * vertices;
	cin>>n;

	arr=(int **)calloc(n+1,sizeof(int*));
	tree=(int **)calloc(n+1,sizeof(int*));
	ans=(int **)calloc(n+1,sizeof(int*));
	visited=(int *)calloc(n+1,sizeof(int));

	for(i=0;i<=n;i++){
		arr[i]=(int *)calloc(n+1,sizeof(int));		
		tree[i]=(int *)calloc(n+1,sizeof(int));			
		ans[i]=(int *)calloc(n+1,sizeof(int));				
	}


	int check1,check2,j,sum=0;

	check1=1;
	check2=1;

	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			cin>>arr[i][j];
			sum+=arr[i][j];
		}
	}

	for(i=0;i<n;i++){
		for(j=0;j<n && check1;j++){
			if(i==j){
				if(arr[i][j]!=0){
					check1=0;
					break;	
				}
			}
			else{
				if(arr[i][j]!=arr[j][i]){
					check1=0;
					break;
				}
			}
		}
	}
	for(i=0;i<n && check1;i++){
		for(j=i+1;j<n && check1;j++){
			new_edge=(struct Edge *)malloc(sizeof(struct Edge));
			new_edge->src=i;
			new_edge->dest=j;
			new_edge->weight=arr[i][j];
			edges.push_back(*new_edge);
		}	
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
			//mst_weight+=edges[i].weight;
			A.push_back(*new_edge);
			Union(vertices,u,v);
		}
	}
	//sort(A.begin(),A.end(),cmp);

	for(i=0;i<A.size();i++){
		tree[A[i].src][A[i].dest]=A[i].weight;
		tree[A[i].dest][A[i].src]=A[i].weight;
		ans[A[i].src][A[i].dest]=A[i].weight;
		ans[A[i].dest][A[i].src]=A[i].weight;
	}
/*
	for(i=0;i<n;i++){
		for (j= 0; j < n;j++)
		{
			cout<<ans[i][j]<<"\t";
		}
		cout<<endl;
	}
*/
	for(i=0;i<n;i++){
		//memset(visited,0,n+1);
		for(j=0;j<=n;j++)
			visited[j]=0;
		//cout<<endl;
		dfs(i,i,n);
	}

	
	for(i=0;i<n && check2;i++){
		for(j=0;j<n && check2;j++){
			if(arr[i][j]!=ans[i][j]){
				check2=0;
				break;
			}
		}
	}
	
	/*
	for(i=0;i<n;i++){
		for (j= 0; j < n;j++)
		{
			cout<<ans[i][j]<<"\t";
		}
		cout<<endl;
	}
	*/
	if((check1 && check2 && sum)||(n==1 && sum==0))
		cout<<"YES\n";
	else
		cout<<"NO\n";
	/*
	printf("%.2lf\n",mst_weight);
	for(i=0;i<A.size();i++){
	if(A[i].src<A[i].dest)	
		printf("%d %d %.2lf\n",A[i].src,A[i].dest,A[i].weight);
	else
		printf("%d %d %.2lf\n",A[i].dest,A[i].src,A[i].weight);	
	}	
	*/
	return 0;
}