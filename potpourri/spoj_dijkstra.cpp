#include<stdio.h>
#include<stdlib.h>
#include<vector>
#include<algorithm>
#include<iostream>
#include<limits.h>
#include<stack>
using namespace std;

struct AdjListNode{
	int dest;
	int weight;
	struct AdjListNode * next;
};

struct AdjList{
	struct AdjListNode * head;
};

struct Graph{
	int V;
	struct 	AdjList* array;
};

struct AdjListNode* newAdjListNode(int dest,int weight){
	struct AdjListNode * newnode = (struct AdjListNode * )malloc(sizeof(struct AdjListNode));
	newnode->dest=dest;
	newnode->weight=weight;
	newnode->next=NULL;
	return newnode;
}

struct Graph* createGraph(int V){
	struct Graph * graph=(struct Graph *) malloc(sizeof(struct Graph));
	graph->V=V;
	
	graph->array=(struct AdjList*) malloc(V*sizeof(struct AdjList));
	
	int i;
	for (i=0;i<V;i++)
		graph->array[i].head=NULL;
	return graph;	
}

void AddEdge(struct Graph* graph,int source,int dest,int weight){
	struct AdjListNode * newnode;
	//cout<<"Hi AddEdge\n";
	newnode=newAdjListNode(dest,weight);
	newnode->next=graph->array[source].head;
	graph->array[source].head=newnode;
	
	/*
	newnode=newAdjListNode(source,weight);
	newnode->next=graph->array[dest].head;
	graph->array[dest].head=newnode;*/	
}

void printGraph(Graph * graph){
	int v,i;
	struct AdjListNode * temp ,*temp1;
	v=graph->V;
	for(i=0;i<v;i++){	
		temp=graph->array[i].head;
		temp1=temp;
		//cout<<"In print\n";
		while(temp!=NULL){
			printf("Edge %d is connected to edge %d with weight %d\n ",i,temp->dest,temp->weight);
			temp=temp->next;
		}		
		graph->array[i].head=temp1;
	}
}

struct graph_helper{
	int v;
	int key;
	int parent;
};

int PARENT(int i){
	return i/2;
}
int LEFT(int i){
	return 2*i;
}
int RIGHT(int i){
	return 2*i+1;
}

void swap(struct graph_helper *a,struct graph_helper *b){
	struct graph_helper temp;
	temp=*a;
	*a=*b;
	*b=temp;
	return;
}


void MINHEAPIFY(struct graph_helper *A,int i,int n,int *pos){
	int smallest,l,r,k;
	l=LEFT(i);
	r=RIGHT(i);
	//for(k=1;k<=n;k++)
	//	cout<<"In MINHEAPIFY"<<A[k].key<<endl;
	if (l<=n && A[l].key<A[i].key)
		smallest=l;
	else 
		smallest=i;
	
	if(r<=n && A[r].key<A[smallest].key)
		smallest=r;
	
	//cout<<"Smallest="<<smallest<<endl;
	
	if (smallest!=i){
		pos[A[smallest].v+1]=i;
		pos[A[i].v+1]=smallest;
		
		swap(&A[i],&A[smallest]);
		MINHEAPIFY(A,smallest,n,pos);	
	}			
}
void BUILDMINHEAP(struct graph_helper *A,int n,int *pos){
	int i;
	for(i=n/2;i>=1;i--){
		MINHEAPIFY(A,i,n,pos);
	}
}

struct graph_helper HEAPMINIMUM (struct graph_helper *A){
	return A[1];
}

struct graph_helper HEAPEXTRACTMIN(struct graph_helper *A,int n,int * pos){
	struct graph_helper min;
	min.key=-1;
	if(n==0){
		cout<<"Invalid Extract\n";		
		//return NULL;
	}	
	else{
		pos[A[1].v+1]=n;
		pos[A[n].v+1]=1;
	
		min=A[1];
		A[1]=A[n];
		MINHEAPIFY(A,1,n-1,pos);
	}
	return min;
}

void HEAPDECREASEKEY(struct graph_helper *A,int i,int key,int *pos){
	if (key > A[i].key){
		cout<<"Key Is greater than already present key\n";		
	}
	A[i].key=key;
	while(i>1 && A[PARENT(i)].key>A[i].key){
		
		pos[A[i].v+1]=PARENT(i);
		pos[A[PARENT(i)].v+1]=i;
		swap(&A[PARENT(i)],&A[i]);
		i=PARENT(i);
	}
}

void graph_free(Graph * graph,int v){
	//stack < struct AdjListNode * > mystack;
	struct AdjListNode * temp;
	struct AdjListNode * node;
	
	int i;
	
	for(i=0;i<v;i++){
		temp=graph->array[i].head;
		while(temp!=NULL){
			node=temp;
			temp=temp->next;
			//cout<<"Weight"<<node->weight<<endl;
			free(node);
		}
	}
	free(graph->array);
	free(graph);
}

int main(){
	int m,u,src,dest,v,ch,ch1,n,flag=1,k;
	int weight,mst_weight=0,start,end,dist,p,q;
	Graph* graph;
	dist=-1;

	struct graph_helper* A;
	struct graph_helper min;
	struct AdjListNode * temp;
	
	int *pos;
	int i,key;
	
	p=0;
	cin>>q;
	//cout<<v<<endl;
	//scanf("%d %d",&v,&m);
	for(p=0;p<q;p++){
	cin>>v>>m;
	n=v;
	k=v;
	A=(struct graph_helper*) malloc(2*n*sizeof(struct graph_helper));
	pos=(int *)malloc(2*n*sizeof(int));
	temp=(struct AdjListNode *)malloc(sizeof(struct AdjListNode));
	
	graph=createGraph(v);
	for(i=1;i<=m;i++){
		scanf("%d %d %d",&src,&dest,&weight);
		AddEdge(graph,src-1,dest-1,weight);
	}
	//printGraph(graph);
	
	
	//cout<<"Here";	
	
	//Dijkstra's  Algorithm Starts
	
	cin>>start>>end;

	for(i=1;i<=n;i++){
		A[i].v=i-1;
		A[i].key=INT_MAX;
		A[i].parent=-1;
		pos[A[i].v+1]=i;
	}
	A[start].key=0;
	swap(&A[start],&A[1]);
	
	while(n>0){
	
		min=HEAPEXTRACTMIN(A,n,pos);n--;		
		u=min.v;
		//mst_weight+=min.key;
		//cout<<"Inside u\n u: "<<u<<" key : "<<min.key<<endl;
		//cout<<u<<endl;
		if(u==end-1)
			dist=min.key;
		temp=graph->array[u].head;
		
		while(temp!=NULL){
			//cout<<"Inside while\n";
			v=temp->dest;
			weight=temp->weight;
			if(pos[v+1]<=n && weight+min.key<A[pos[v+1]].key){		
				A[pos[v+1]].parent=u;
				HEAPDECREASEKEY(A,pos[v+1],weight+min.key,pos);
			}
			temp=temp->next;	
		}
		
	}
	if(dist!=-1 && dist!=INT_MAX)
		cout<<dist<<endl;
	else
		cout<<"NO\n";
	
		free(A);
		free(pos);
		free(temp);
		//cout<<"k: "<<k<<endl;
		graph_free(graph,k);	
	}		
	//for(i=1;i<k;i++){
	//	cout<<A[i].v<<"\t"<<A[i].parent<<"\t"<<A[i].key<<endl;
	//}
	return 0;
}
