#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string>
#include<cctype>
using namespace std;

char arr[100001];

int main(){
	long long int dummy,i,n,k,w,l,r,res,j;
	//string arr;
	cin>>n>>k>>w;
	cin>>dummy;
	//getline(cin,arr);
	for(i=1;i<=n;i++)
		cin>>arr[i]; 
	cin>>dummy;
	for(i=1;i<=n;i++)
		cout<<arr[i]; 
	
	for(i=1;i<=w;i++){
		cin>>l>>r;
		res=0;
		for(j=l+k-1;j<=r;j+=k){
			if(arr[j]=='0')
				res++;
		}
		for(j=l;j<=r;j++){
			if((j-l+1)%k==0){
				continue;
			}
			else{
				if(arr[j]=='1')
					res++;
			}
		}
			cout<<res<<endl;
	}

	return 0;
}
