#include <stdio.h>
#include <iostream>

using namespace std;

int main(){

	long long int t,n;
	scanf("%lld",&t);
	while(t--){
		scanf("%lld",&n);
		printf("%lld\n",(n*(n+3))/2);
	}

	return 0;
}