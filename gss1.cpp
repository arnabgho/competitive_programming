#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;	

int tree[200000];

#define INF 100000;

int parent(int i){
	return i/2;
}
int left_child(int i){
	return 2*i;
}
int right_child(int i){
	return 2*i+1;
}


int isPowerOf2(int n){
	return (n&(n-1)==0);
}

void initialize(int start){
	for(int i=start;i>=1;i--){
		tree[i]=tree[left_child(i)]+tree[right_child(i)];
	}
}

int query(int node,int b,int e,int x,int y,int h){
	//cout<<"Node: "<<node<<endl;
	if(node>(1<<(h+1)))
		return -INF;
	if(e<x || b>y)
		return -INF;
	int left_ans,right_ans,maxim;

	left_ans=query(2*node,b,(b+e)/2,x,y,h);
	right_ans=query(2*node+1,(b+e)/2+1,e,x,y,h);
	maxim=max(left_ans,right_ans);
	if(b>=x && e<=y)
		maxim=max(maxim,tree[node]);
	return maxim;
}	

int main(){
	int i,x,y,n,h,level_of_tree,root=1,m,ans;
	scanf("%d",&n);
	if(!isPowerOf2(n))
		h=log2(n)+1;
	else
		h=log2(n);

	level_of_tree=(1<<h);
	for(i=level_of_tree;i<level_of_tree+n;i++)
		scanf("%d",&tree[i]);
	//cout<<"Ho";
	initialize(level_of_tree-1);
	scanf("%d",&m);
	for(i=1;i<=m;i++){
		scanf("%d %d",&x,&y);
		ans=query(1,1,n,x,y,h);
		printf("%d\n",ans );
	}
	return 0;
}