#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>

using namespace std;

struct node{


};

node range_query(node * tree,int root,int left_most_leaf,int right_most_leaf,int u,int v){
	if(u<=left_most_leaf && v>=right_most_leaf)
		return tree[root];

	int mid=(left_most_leaf+right_most_leaf)/2;
	int left_child=root*2;
	int right_child=left_child+1;
	tree[root].split(tree[left_child],tree[right_child]);
	node
}

void mergeup(){

}

void update(){

}


int main()
{
	
	return 0;
}