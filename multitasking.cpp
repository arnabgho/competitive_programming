#include<stdio.h>
#include<stdlib.h>
#include<iostream>

using namespace std;

void swap(int * p1,int * p2){
	int temp;
	temp=*p1;
	*p1=*p2;
	*p2=temp;
}

int res[5000][2];
int arr[1001][101];
int main(){
	int i,j,n,m,k,pos,l,p;
	cin>>n>>m>>p;
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			cin>>arr[i][j];
		}	
	}
	pos=1;
	for(i=1;i<=n;i++){
		for(j=1;j<=m-1;j++){
			for(k=j+1;k<=m;k++){
				if(p==0){
				if(arr[i][j]>arr[i][k]){
					swap(&arr[i][j],&arr[i][k]);
					res[pos][0]=j;
					res[pos][1]=k;
					pos++;
					for(l=i+1;l<=n;l++){
						if(arr[l][j]>arr[l][k]){
							swap(&arr[l][j],&arr[l][k]);
						}			
					}
				}
				}
				if(p==1){
				if(arr[i][j]<arr[i][k]){
					swap(&arr[i][j],&arr[i][k]);
					res[pos][0]=k;
					res[pos][1]=j;
					pos++;
					for(l=i+1;l<=n;l++){
						if(arr[l][j]<arr[l][k]){
							swap(&arr[l][j],&arr[l][k]);
						}			
					}
				}				
				}
			}	
		}	
	}
	cout<<pos-1<<endl;
	for(i=1;i<=pos-1;i++){
		cout<<res[i][0]<<" "<<res[i][1]<<endl;
	}
	
	return 0;
}