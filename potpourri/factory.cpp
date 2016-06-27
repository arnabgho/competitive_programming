#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

bool isPowerOf2(int n){
	return ((n & (n-1))==0);
}

int gcd(int a,int b){
	if(b==0)
		return a;
	return gcd(b,a%b);
}

int main(){

	int a,m,ans;
	cin>>a>>m;
	while(m%2==0){
		m/=2;
	}
	if(gcd(m,a)==1)
		ans=0;
	else
		ans=1;
	if(m==1)
		ans=1;
	if(ans)
		cout<<"Yes\n";
	else
		cout<<"No\n";
	return 0;
}