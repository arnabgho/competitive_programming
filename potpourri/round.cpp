#include<stdio.h>
#include<stdlib.h>
#include<iostream>

using namespace std;

int arrn[4000][2];
int arrm[4000][2];
int main(){
	int n,m,i,j,count,val;
	cin>>n>>m;
	for(i=1;i<=n;i++)
		cin>>arrn[i][0];
	for(j=1;j<=m;j++)
		cin>>arrm[j][0];
		
	for(i=1;i<=n;i++){
		val=arrn[i][0];
		for(j=1;j<=m;j++){
			if(val<=arrm[j][0] && arrm[j][1]==0){
				arrn[i][1]=1;
				arrm[j][1]=1;
				break;
			}
		}
	}	
	count=0;	
	for(i=1;i<=n;i++){
		if(arrn[i][1]==0)
			count++;
	}
	cout<<count<<endl;
	return 0;
}
