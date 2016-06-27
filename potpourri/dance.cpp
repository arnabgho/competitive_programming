#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

struct entry{
	int M,W,S;
};

bool cmp(struct entry a,struct entry b){
	return a.S>b.S;
}


struct entry arr[100001];

int main(){
	int n,i;
	cin>>n;
	for(i=0;i<n;i++){
		cin>>arr[i].M;
		cin>>arr[i].W;
		cin>>arr[i].S;
	}
	sort(arr,arr+n,cmp);
	/*
	for(i=0;i<n;i++){
		cout<<arr[i].M<<"\t"<<arr[i].W<<"\t"<<arr[i].S<<endl;
	}*/

		


	return 0;
}