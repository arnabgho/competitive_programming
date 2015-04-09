#include <stdio.h>
#include <stdlib.h>
#include <stack>
#include <iostream>
using namespace std;

long long int gcd(long long int a,long long int b){
	return (b!=0)? gcd(b,a%b):a;
}

long long int gcd_store[100001];

int main(){
	long long int t,c,n,i,k;
	scanf("%lld",&t);
	while(t--){
		scanf("%lld",&n);
		scanf("%lld",&k);
		//cout<<"n"<<n<<endl;
		gcd_store[1]=k;
		for(i=2;i<=n;i++){
			scanf("%lld",&k);
			gcd_store[i]=gcd(gcd_store[i-1],k);
		}
		if(gcd_store[n]==1)
			printf("%lld\n",n);
		else
			printf("-1\n");
	}
	return 0;
}