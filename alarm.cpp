#include<stdio.h>
#include<stdlib.h>
#include<iostream>

using namespace std;

int x[101];
int y[101];
	
int min(int a, int b){
	return a<b ? a:b;
}		
int main(){

	int nx,ny,a,b,n,i;
	cin>>n;	
	for(i=1;i<=n;i++){
		cin>>a>>b;
		x[a]++;
		y[b]++;
	}
	nx=0;
	ny=0;
	for(i=0;i<=100;i++){
		if(x[i]>0)
			nx++;
		if(y[i]>0)
			ny++;		
	}
	cout<<min(nx,ny);
	return 0;
}