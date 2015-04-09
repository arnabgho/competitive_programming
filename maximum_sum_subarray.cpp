#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;;

int DP[100];
int arr[100];
#define INF 100000;

int main(int argc, char const *argv[])
{
	int i,n,maxim;
	cin>>n;
	maxim=-INF;
	for(i=0;i<n;i++)
		cin>>arr[i];
	DP[0]=arr[0];
	for(i=1;i<n;i++){
			
			DP[i]=max(DP[i-1]+arr[i],arr[i]);
		
		maxim=max(maxim,DP[i]);
	}
	cout<<maxim<<endl;

	return 0;
}