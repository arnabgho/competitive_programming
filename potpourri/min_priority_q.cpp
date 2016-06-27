#include<stdio.h>
#include<stdlib.h>
#include<vector>
#include<algorithm>
#include<iostream>
#include<limits.h>

using namespace std;

int A[10001];
int PARENT(int i){
	return i/2;
}
int LEFT(int i){
	return 2*i;
}
int RIGHT(int i){
	return 2*i+1;
}

void swap(int *a,int *b){
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
	return;
}


void MINHEAPIFY(int *A,int i,int n){
	int smallest,l,r,k;
	l=LEFT(i);
	r=RIGHT(i);
	//for(k=1;k<=n;k++)
	//	cout<<A[k]<<endl;
	if (l<=n && A[l]<A[i])
		smallest=l;
	else 
		smallest=i;
	
	if(r<=n && A[r]<A[smallest])
		smallest=r;
	
	//cout<<"Smallest="<<smallest<<endl;
	
	if (smallest!=i){
		swap(&A[i],&A[smallest]);
		MINHEAPIFY(A,smallest,n);	
	}			
}
void BUILDMINHEAP(int *A,int n){
	int i;
	for(i=n/2;i>=1;i--){
		MINHEAPIFY(A,i,n);
	}
}

int HEAPMINIMUM (int *A){
	return A[1];
}

int HEAPEXTRACTMIN(int *A,int n){
	int min;
	if(n==0){
		cout<<"Invalid Extract\n";		
		return -1;
	}	
	else{
		min=A[1];
		A[1]=A[n-1];
		MINHEAPIFY(A,1,n-1);
	}
	return min;
}

void HEAPDECREASEKEY(int *A,int i,int key){
	if (key > A[i]){
		cout<<"Key Is greater than already present key\n";		
	}
	A[i]=key;
	while(i>1 && A[PARENT(i)]>A[i]){
		swap(&A[PARENT(i)],&A[i]);
		i=PARENT(i);
	}
}

void MINHEAPINSERT(int *A,int key,int n){
		
	A[n+1]=INT_MAX;
	HEAPDECREASEKEY(A,n+1,key);
}

int main(){

	int n,i,ch,key,min;
	cin>>n;

	for(i=1;i<=n;i++)
		cin>>A[i];
	//swap(&A[1],&A[2]);
	//cout<<A[1]<<A[2]<<endl;

	BUILDMINHEAP(A,n);
	for(i=1;i<=n;i++)
		cout<<A[i]<<endl;
		
	while(1){
		cout<<"1 for insert, 2 for decrease key , 3 for extract min\n";
		cin>>ch;
		switch(ch){
			case 1:
				cin>>key;
				MINHEAPINSERT(A,key,n++);
				break;
			case 2:
				cin>>key>>i;
				HEAPDECREASEKEY(A,key,i);
				break;	
			case 3:
				min=HEAPEXTRACTMIN(A,n--);
				cout<<"Min="<<min<<endl;
				break;
		}		
		for(i=1;i<=n;i++)
			cout<<A[i]<<endl;
	}	
	return 0;
}
