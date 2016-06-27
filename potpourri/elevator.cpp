#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>

using namespace std;

int arr[2500];
int main(){
	int n,k,i,ans;
	cin>>n>>k;
	for(i=0;i<n;i++)
		cin>>arr[i];
	sort(arr,arr+n);
	ans=0;
	while(n>0){
		ans+=2*arr[n-1]-2;
		if(n>k){
			n-=k;
		}
		else{
			n=0;
		}
	}
	cout<<ans<<endl;
	return 0;
}