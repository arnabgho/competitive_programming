#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

void initialize(int node,int b,int e,int *M,int *A,int N){
	cout<<"b: "<<b<<" e :"<<e<<endl;
	cout<<"node: "<<node<<endl;
	if(b>e)
		return;	

	if(b==e)
		M[node]=b;
	else{
		initialize(node<<1,b,(b+e)/2,M,A,N);
		initialize((node<<1)+1,(b+e)/2+1,e,M,A,N);

		if(A[M[node<<1]]<=A[M[(node<<1)+1]])
			M[node]=M[node<<1];
		else
			M[node]=M[(node<<1)+1];
	}
}

int query(int node,int b,int e,int *M,int *A,int i,int j){
	int p1,p2;

	if(i>e || j<b)
		return -1;

	else if(b>=i && e<=j)
		return M[node];

	p1=query(node<<1,b,(b+e)/2,M,A,i,j);
	p2=query((node<<1)+1,(b+e)/2+1,e,M,A,i,j);

	if(p1==-1 )
		return p2;
	if(p2==-1)
		return p1;
	if(A[p1]<=A[p2])
		return M[node]=p1;
	
	return M[node]=p2;
}


int main(){
	int n,m,i,j;
	int *M,*A;
	

	cout<<"Enter the number of elements: \n";
	cin>>n;
	m=log(n)+1;
	cout<<"m: "<<m<<endl;
	M=(int *)malloc((1<<(m+1)+1)*sizeof(int));
	A=(int *)malloc(n*sizeof(int));

	for(i=0;i<n;i++){
		cin>>A[i];
		M[(1<<m)+i]=i;
	}
	cout<<"Hi"<<endl;

	initialize(1,0,n-1,M,A,n);

	for(i=1;i<(1<<m)+n;i++)
		cout<<"i: "<<i<<" min range pos : "<<M[i]<<endl;
	
	int ex=0;
	while(!ex){
		cout<<"enter the range : \n";
		cin>>i>>j;
		cout<<A[query(1,0,n-1,M,A,i,j)]<<endl;
		cout<<"wanna exit ? (y=1/n=0).............\n";
		cin>>ex;
	}
	return 0;
}