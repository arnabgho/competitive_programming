#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<iostream>

using namespace std;

int arr[501];

int main(){
	int i,n,c,maxdiff;
	cin>>n>>c;
	for(i=1;i<=n;i++){
		cin>>arr[i];	
	}
	maxdiff=0;
	for(i=1;i<n;i++){
		if(arr[i]>arr[i+1]){
			if(arr[i]-arr[i+1]>maxdiff){
				maxdiff=arr[i]-arr[i+1];
			}
		}		
	}
	//cout<<maxdiff<<endl;
	if(maxdiff==0){
		cout<<'0'<<endl;
	}
	else{
		if((maxdiff-c)<=0)
			cout<<'0'<<endl;
		else
			cout<<maxdiff-c<<endl;	
	}
	return 0;
}
