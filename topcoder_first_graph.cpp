#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include <list>
#include<limits.h>
#include<set>
#include<utility>
#include<algorithm>
#include<iterator>
#include<string>

using namespace std;

typedef  int vertex_t;
typedef  int  weight_t;

const weight_t max_weight_t=std::numeric_limits<double>::infinity();

struct neighbor{

	vertex_t target;
	weight_t weight;
	neighbor(vertex_t arg_target,weight_t arg_weight): target(arg_target),weight(arg_weight){}
};

typedef std::vector<std::vector<neighbor>> adjacency_list_t;

int min(int a,int b){return a<b ? a:b;}

class ColorfulRoad{
public:
	int getMin(string road){
		int n,i,j;
		char ch,ch1;
		int *dp;
		n=road.length();
		dp=(int *)malloc(n*sizeof(int));
		adjacency_list_t adjacency_list(n);
		for(i=0;i<n-1;i++){
			ch=road.at(i);
			for(j=i+1;j<n;j++){
				ch1=road.at(j);
				if(ch=='R'&&ch1=='G'){
					adjacency_list[i].push_back(neighbor(j,(j-i)*(j-i)));
					//cout<<"i: "<<i<<" j: "<<j<<" j-i : "<<(j-i)*(j-i)<<endl;
				}
				else if(ch=='G'&&ch1=='B'){
					adjacency_list[i].push_back(neighbor(j,(j-i)*(j-i)));
					//cout<<"i: "<<i<<" j: "<<j<<" j-i : "<<(j-i)*(j-i)<<endl;
				}
				else if(ch=='B'&&ch1=='R'){
					adjacency_list[i].push_back(neighbor(j,(j-i)*(j-i)));
					//cout<<"i: "<<i<<" j: "<<j<<" j-i : "<<(j-i)*(j-i)<<endl;
				}
			}
		}
		dp[0]=0;
		for(i=1;i<n;i++){
			dp[i]=100000000;
			cout<<"dp : "<<dp[i]<<endl;
		}	
			
		
		cout<<" max_weight : "<<max_weight_t<<endl;	
			
		for(i=0;i<n-1;i++){
			const std::vector<neighbor> &neighbors=adjacency_list[i];
			for(std::vector<neighbor>::const_iterator neighbor_iter=neighbors.begin();neighbor_iter!=neighbors.end();neighbor_iter++){
				vertex_t v=neighbor_iter->target;
				weight_t w=neighbor_iter->weight;
				dp[v]=min(dp[v],w+dp[i]);		
				cout<<"v: "<<v<<" weight: "<<w<<" dp[v] : "<<dp[v]<<endl;
					
			}
		}	
		if(dp[n-1]!=100000000)
			return dp[n-1];
		else
			return -1;
	}

};