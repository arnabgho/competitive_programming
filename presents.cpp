#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;
#define INF 1000000000000;
long long int maxim;
bool isPossible(long long int n,long long int cnt1,long long int cnt2,long long int x,long long int y){
	if(!maxim){
		return (n-n/x)>=cnt1 && ((n-n/(x*y))>=cnt1+cnt2);
	}
	else{
		return (n-n/y)>=cnt2 && ((n-n/(x*y))>=cnt1+cnt2);
	}
}


long long int binsearch(long long int cnt1,long long int cnt2,long long int x,long long int y,long long int left,long long int right){
	if(left>right)
		return INF;
	long long int mid=(left+right)/2;
	if(isPossible(mid,cnt1,cnt2,x,y)){
		return min(mid,binsearch(cnt1,cnt2,x,y,left,mid-1));
	}
	else
		return binsearch(cnt1,cnt2,x,y,mid+1,right);
}

int main(){
	long long int cnt1,cnt2,x,y,ans;

	cin>>cnt1>>cnt2>>x>>y;
	if(cnt1>cnt2)
		maxim=0;
	else
		maxim=1;
	ans=binsearch(cnt1,cnt2,x,y,1,cnt1*x+cnt2*y);
	cout<<ans<<endl;

	return 0;
}