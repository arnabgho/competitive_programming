#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<stdlib.h>

using namespace std;

long long int arr[1000001];

int main(){
	long long int n,i,val,j,k;
	cin>>n;
	for(i=0;i<n;i++){
		cin>>arr[i];
	}
	sort(arr,arr+n);
	val=0;
	k=2;
	for(j=0;j<n-1;j++){
		val+=(k)*arr[j];
		k++;
	}
	k--;
	val+=(k)*arr[n-1];
	cout<<val<<endl;
	return 0;
}
