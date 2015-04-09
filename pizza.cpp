#include <stdio.h>
#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;

#define INF 1000000;
int DP[1001];

void compute(){
	DP[1]=0;
	DP[2]=1;
	DP[3]=2;
	for(int i=4;i<=1000;i++){
		if(i%2==0)
			DP[i]=DP[i/2]+1;
		else
			DP[i]=DP[i/2]+2;
	}
}

bool isPossible(int n,int p){
	return n*n+n+2-2*p>=0;
}

int bin(int left,int right,int p){
	if(left>right || left<0 || right>p )
		return INF;
	int mid=(left+right)/2;
	if(isPossible(mid,p)){
		return min(mid,bin(left,mid-1,p));
	}
	return bin(mid+1,right,p);
}	

int main()
{
	int t,n,res;
	double ans;
	cin>>t;
	//compute();
	while(t--){
		cin>>n;
		res=bin(0,n,n);
		cout<<res<<endl;
	}
	/* code */
	return 0;
}