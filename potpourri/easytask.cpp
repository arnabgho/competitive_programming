#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<stdlib.h>

using namespace std;

int arr[102][102];

int main(){

	int n,i,val=1,k,j;
	char ch;
	cin>>n;
	
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			cin>>ch;
			if(ch=='o')
				arr[i][j]++;
		}
	}

	k=0;
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			k=arr[i-1][j]+arr[i+1][j]+arr[i][j+1]+arr[i][j-1];
			if(k%2==1){
				val=0;
				break;
			}
		}	
		if (val==0)
			break;
	}
	if(val>0)
		cout<<"YES\n";
	else
		cout<<"NO\n";	
	return 0;
}
