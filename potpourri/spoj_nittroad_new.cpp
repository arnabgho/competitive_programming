#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;

struct Edge{
	int src,dest;
	int weight;
};

bool cmp(struct Edge  a,struct Edge b){
	return a.weight<b.weight;
}

struct Set{
	int parent,rank,number_nodes;
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
	
	if(vertices[i_dash].rank<vertices[j_dash].rank){
		vertices[i_dash].parent=j_dash;
		vertices[j_dash].number_nodes+=vertices[i_dash].number_nodes;
	}
	else if(vertices[i_dash].rank>vertices[j_dash].rank){
		vertices[j_dash].parent=i_dash;
		vertices[i_dash].number_nodes+=vertices[j_dash].number_nodes;		
	}
	else{
		vertices[i_dash].parent=j_dash;
		vertices[j_dash].rank++;
		vertices[j_dash].number_nodes+=vertices[i_dash].number_nodes;		
	}		
}	
int Make_set(struct Set * vertices,int n){
	int i;
	for(i=0;i<n;i++){
		vertices[i].parent=i;
		vertices[i].rank=0;
		vertices[i].number_nodes=1;
	}
}

vector<struct Edge> edges;
vector<struct Edge> A;
int m,u,v,i,n,src,dest,flag=1,ch,ch1;
int t,p;
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


typedef pair<int,int> PI;
stack <char> mystack;
stack <PI> Qedges;
stack <int> ans;
int main()
{
	int t,Q,disco,a,b;
	cin>>t;
	char ch;
	string s;
	pair<int,int> temp;
	while(t--){
		cin>>n;
		for(i=0;i<n-1;i++){
			cin>>src>>dest;
			new_edge=(struct Edge *)malloc(sizeof(struct Edge));
			new_edge->src=src-1;
			new_edge->dest=dest-1;
			new_edge->weight=1;
			edges.push_back(*new_edge);			
		}
		vertices=(struct Set *)malloc(n*sizeof(struct Set));
		Make_set(vertices,n);
		cin>>Q;
		while(Q--){
			cin>>ch;
			mystack.push(ch);
			if(ch=='R'){
				cin>>src>>dest;
				src--;dest--;
				temp=make_pair(src,dest);
				Qedges.push(temp);
			}
		}
		disco=n*(n-1);
		disco/=2;
		while(!mystack.empty()){
			ch=mystack.top();
			cout<<ch<<endl;
			mystack.pop();
			if (ch=='Q')
			{
				ans.push(disco);
			}
			else{
				temp=Qedges.top();
				Qedges.pop();
				src=temp.first;
				dest=temp.second;
				a=Find_set(vertices,src);
				b=Find_set(vertices,dest);
				disco-=a*b;
			}
		}
		while(!ans.empty()){
			cout<<ans.top()<<endl;
			ans.pop();
		}
		free(vertices);
		edges.clear();
		A.clear();
	}
	return 0;
}
