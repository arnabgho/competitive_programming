#include <queue>
#include <stdio.h>
#include <iostream>
using namespace std;

const int INF = 2000000000;

typedef pair<int,int> PII;

int main(){
	int N,s,t,M,i,j,k;
	cin>>N>>s>>t;
	std::vector< vector<PII> > edges(N);
	for (int i = 0; i < N; i++){
	    scanf ("%d", &M);
	    for (int j = 0; j < M; j++){
	      int vertex, dist;
	      scanf ("%d%d", &vertex, &dist);
	      edges[i].push_back (make_pair (dist, vertex)); // note order of arguments here
	    }
  	}
  	std::vector<int> shortest_path_weight(N,INF);
  	std::vector<int> parent(N,-1);
  	shortest_path_weight[s]=0;

  	for(k=0;k<N-1;k++){
	  	for(i=0;i<N;i++){
	  		for(j=0;j<edges[i].size();j++){
	  			int u,v,w;
	  			u=i;v=edges[i][j].second;w=edges[i][j].first;
	  			if(shortest_path_weight[u]+w<shortest_path_weight[v]){
	  				shortest_path_weight[v]=shortest_path_weight[u]+w;
	  				parent[v]=u;
	  			}
	  		}
	  	}
	}  	
	bool exists_negative_cycle=false;
	for(i=0;i<N;i++){
	  	for(j=0;j<edges[i].size();j++){
	  		int u,v,w;
	  		u=i;v=edges[i][j].second;w=edges[i][j].first;
	  		if(shortest_path_weight[u]+w<shortest_path_weight[v]){
	  				exists_negative_cycle=true;break;
	  		}
	  	}
	}
	
  	return 0;
} 	