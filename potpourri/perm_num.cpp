#include<stdio.h>
#include<stdlib.h>

long long int arr[1000001];

static long long int N=1000000007;

void compute(){
	arr[1]=1;
	arr[2]=1;
	long long int i;
	for (i=3;i<=1000000;i++){
		arr[i]=(((i-1)*arr[i-1])%N+((i-2)*arr[i-2])%N)%N;
	}
}

int main(){
	long long int i,j,c,t,n;
	scanf("%lld",&t);
	c=0;
	compute();
	while(c++<t){
		scanf("%lld",&n);
		printf("Case %lld: %lld\n",c,arr[n]);
	}
	return 0;
}
