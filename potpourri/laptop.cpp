#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<iostream>
using namespace std;

struct data{
	int a,b;
};

bool cmp(data x,data y){
	return (x.a<y.a);
}

data arr[100001];
int main(){
	int n,i,j,tr;
	cin>>n;
	for(i=0;i<n;i++)
		cin>>arr[i].a>>arr[i].b;
	
	sort(arr,arr+n,cmp);
	tr=0;
	for(i=0;i<n-1;i++){
		if(arr[i].b>arr[i+1].b){
			tr=1;
		}	
	}
	if (tr){
		cout<<"Happy Alex\n";
	}
	else{
		cout<<"Poor Alex\n";
	}
	return 0;
}
