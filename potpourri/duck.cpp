#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<iostream>
#include<algorithm>

using namespace std;
long int DP[100001];
long long int arr[100001];
long long int mod(long long int n){return (n>0) ? n:-n;}
long long int min(long long int a,long long int b){return a<b ? a:b ;}
int main()
{
	long long int n,i,x,y;

	cin>>n;
	for(i=0;i<n;i++)
		cin>>arr[i];

	sort(arr,arr+n);

	DP[0]=0;
	DP[1]=arr[1]-arr[0];
	DP[2]=mod(arr[2]-arr[1])+DP[1];
	for(i=3;i<n;i++){
		//x=arr[i]-arr[i-2]+DP[i-1];
		y=arr[i]-arr[i-1]+DP[i-2];
		DP[i]=y;
	}

	for(i=0;i<n;i++){
		cout<<DP[i]<<endl;
	}
	cout<<DP[n-1]<<endl;
	/* code */
	return 0;
}