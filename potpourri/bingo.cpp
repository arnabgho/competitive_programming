#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

long long int arr[101][103];


int main(){
	
	long long int k,j,i,n,m,dummy,flag,test,sum;
	cin>>n;
	for(i=1;i<=n;i++){
		cin>>m;
		arr[i][101]=m;
		for(j=1;j<=m;j++){
			cin>>dummy;
			arr[i][dummy]=1;
		}	
		if(m==1){
			arr[i][102]=dummy;
		}
	}
	for(i=1;i<=n;i++){

		if(arr[i][0]==1)
			continue;
		else{
			flag=0;
			sum=0;
			for(j=1;j<=n && flag==0;j++){
				if(j==i)
					continue;
				else{
					test=0;
					for(k=1;k<=100 && test==0 ;k++){
						if(arr[i][k]!=arr[j][k]){
							test=1;
							break;
						}				
					}
					if(test==0){
						arr[i][0]=1;
						arr[j][0]=1;
						flag=1;
						break;
					}
					sum+=test;			
				}
			}
			arr[i][0]=flag;
		}
		if(arr[i][101]==1){
			for(j=1;j<=n;j++ ){
				dummy=arr[i][102];	
				if(j==i)
					continue;
				if(arr[j][dummy]==1){
					arr[j][0]=1;
				}
			}
		}
	}
	for(i=1;i<=n;i++){
		if(arr[i][0]==1){
			printf("NO\n");
		}
		else
			printf("YES\n");
	}
	return 0;
}
