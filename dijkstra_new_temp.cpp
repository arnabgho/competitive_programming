#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<limits.h>
using namespace std;

struct node{
	int vertex;
	int weight;
};
/*
struct compare{
	bool operator()(const struct node &l,const struct node &r){
		return l.weight>r.weight;
	}
};*/
bool operator<(const node& a, const node& b) {
  return a.weight > b.weight;
}

struct node nodes[10001];
vector< vector <node> > Edges(1000);
vector<int> dist(1000);
int main(){
	priority_queue<node> pq;
	struct node * temp;
	int i,V,K,a,b,c,size,j,A,B,choice;
	cin>>V>>K;
	for(i=1;i<=K;i++){
		cin>>a>>b>>c;
		temp=(struct node *)calloc(1,sizeof(struct node));
		temp->vertex=b;
		temp->weight=c;
		//cout<<"v: "<<temp->vertex<<endl;
		//cout<<"W: "<<temp->weight<<endl;

		Edges[a].push_back(*temp);
	}
	/*
	for(i=1;i<=V;i++){
		size=Edges[i].size();
		for (j=0;j<size;j++)
   			 cout <<"Edge from "<<i<<" to "<<Edges[i][j].vertex<<" With weight "<<Edges[i][j].weight<<endl;
	}
	*/
	cin>>A>>B;
	
	for(i=1;i<=V;i++){
		temp=(struct node *)calloc(1,sizeof(struct node));
		temp->vertex=i;
		if(i==A)
			temp->weight=0;
		else
			temp->weight=INT_MAX;	
			
		pq.push(*temp);	
	}
	/*
	while(1){
		cin>>choice;
		if(choice){
			*temp=pq.top();
			pq.pop();
			cout<<"w: "<<temp->weight<<" vertex: "<<temp->vertex<<endl;
		}
		else
			break;	
	}*/
	
	for(i=1;i<=V;i++){
		*temp=pq.top();
		pq.pop();
		dist[temp->vertex]=temp->weight;
		size=Edges[temp->vertex].size();
		for(j=0;j<size;j++){
			if()
		}	
	}
	return 0;
}
