#include<stdio.h>
#include<stdlib.h>
#include<iostream>

using namespace std;

int arr[101];

int main(){
	int i,n,carry,ans;
	char ch;
	carry=1;
	ans=0;
	cin>>n;
	for(i=1;i<=n;i++){
		cin>>ch;
		arr[i]=ch-48;
		if((carry+arr[i])%2 != arr[i]){
			ans++;
		}	
		//cout<<carry<<endl;
		//cout<<(carry+arr[i])%2<<endl;
		carry=(arr[i]+carry)/2;	
	}
	cout<<ans<<endl;
	return 0;
}
