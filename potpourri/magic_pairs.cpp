#include<stdio.h>
#include<stdlib.h>
using namespace std;

int main(){
	long long int i,c,t,n,dummy;
	scanf("%lld",&t);
	c=0;
	while(c++<t){
		scanf("%lld",&n);
		for(i=1;i<=n;i++)
			scanf("%lld",&dummy);
		printf("%lld\n",(n*(n-1))/2);
	}
	return 0;
}
