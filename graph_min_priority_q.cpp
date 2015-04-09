#include<stdio.h>
#include<stdlib.h>
#include<vector>
#include<algorithm>
#include<iostream>
#include<limits.h>

using namespace std;

struct graph_helper{
	int v;
	double key;
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

void HEAPDECREASEKEY(struct graph_helper *A,int i,double key,int *pos){
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
/*
void MINHEAPINSERT(struct graph_helper *A,struct graph_helper node,int n,int *pos){
		
	A[n+1]=node;	
	A[n+1].key=INT_MAX;
	HEAPDECREASEKEY(A,n+1,node.key,pos);
}
*/
int main(){
	struct graph_helper* A;
	struct graph_helper min;
	int *pos;
	int n,i,ch,key;
	cin>>n;
	A=(struct graph_helper*) malloc(2*n*sizeof(struct graph_helper));
	pos=(int *)malloc(2*n*sizeof(int));
	for(i=1;i<=n;i++){
		scanf("%d %lf %d",&A[i].v,&A[i].key,&A[i].parent);
		pos[A[i].v+1]=i;
	}	
	
	BUILDMINHEAP(A,n,pos);
	
	for(i=1;i<=n;i++){
		cout<<"Node:"<<A[i].v<<endl;
		cout<<"Key:"<<A[i].key<<endl;
		cout<<"Parent:"<<A[i].parent<<endl;
	}
//	for(i=1;i<=n;i++){
//		cout<<"Position of node"<< i<<" in Q : "<<pos[i]<<endl;
//	}
	
	while(1){
		cout<<" 1 for decrease key , 2 for extract min\n";
		cin>>ch;
		switch(ch){
			case 1:
				cin>>key>>i;
				HEAPDECREASEKEY(A,pos[i+1],key,pos);
				break;	
			case 2:
				min=HEAPEXTRACTMIN(A,n,pos);n--;
				cout<<"Min="<<min.key<<endl;
				break;
		}		
		for(i=1;i<=n;i++){
		cout<<"Node:"<<A[i].v<<endl;
		cout<<"Key:"<<A[i].key<<endl;
		cout<<"Parent:"<<A[i].parent<<endl;
	}
	}
	return 0;
}
