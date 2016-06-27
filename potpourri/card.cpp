#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<stdlib.h>

using namespace std;

long long int arr[27];

int main(){
	long long int i,j,n,k,val;

	char ch;
	cin>>n>>k;
	for(i=0;i<n;i++){
		cin>>ch;
		arr[ch-'A']++;
	}
	sort(arr,arr+27);
	val=0;
	i=26;
	//cout<<arr[26]<<endl;
	while(k>0){
		if(arr[i]>=k){
			val+=k*k;
			k=0;	
			break;
		}
		else{
			val+=(arr[i])*(arr[i]);
			k-=arr[i];
			i--;
		}
		//cout<<k<<endl;
	}

	cout<<val<<endl;
	return 0;
}	
	
