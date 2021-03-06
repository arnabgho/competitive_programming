
#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<vector>
#include<algorithm>
#include<iostream>

using namespace std;

struct AdjListNode{
	int dest;
	double weight;
	struct AdjListNode * next;
};

struct AdjList{
	struct AdjListNode * head;
};

struct Graph{
	int V;
	struct 	AdjList* array;
};

struct AdjListNode* newAdjListNode(int dest,double weight){
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

void AddEdge(struct Graph* graph,int source,int dest,double weight){
	struct AdjListNode * newnode;
	//cout<<"Hi AddEdge\n";
	newnode=newAdjListNode(dest,weight);
	newnode->next=graph->array[source].head;
	graph->array[source].head=newnode;
	
	newnode=newAdjListNode(source,weight);
	newnode->next=graph->array[dest].head;
	graph->array[dest].head=newnode;	
}

void printGraph(Graph * graph){
	int v,i;
	struct AdjListNode * temp;
	v=graph->V;
	for(i=0;i<v;i++){	
		temp=graph->array[i].head;
		//cout<<"In print\n";
		while(temp!=NULL){
			printf("Edge %d is connected to edge %d with weight %lf\n ",i,temp->dest,temp->weight);
			temp=temp->next;
		}		
	}
}

int main(){
	int src,dest,v,ch,ch1,n,flag=1;
	double weight;
	Graph* graph;

	scanf("%d\n",&v);
	//cout<<v<<endl;
	graph=createGraph(v);
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
		if(ch1!=-1)
			AddEdge(graph,src,dest,weight);
		else
			break;
	}
	printGraph(graph);
	return 0;
}

/*
int main()
{
    // create the graph given in above fugure
    int V = 5;
    struct Graph* graph = createGraph(V);
    AddEdge(graph, 0, 1,78);
    AddEdge(graph, 0, 4,78);
    AddEdge(graph, 1, 2,576);
    AddEdge(graph, 1, 3,54);
    AddEdge(graph, 1, 4,43);
    AddEdge(graph, 2, 3,34);
    AddEdge(graph, 3, 4,43);
 
    // print the adjacency list representation of the above graph
    printGraph(graph);
 
    return 0;
}
*/
