#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<iostream>

using namespace std;

int main(){
	long long int c,t;
	double result,n;
	c=0;
	scanf("%lld",&t);
	while(c++<t){
		scanf("%lf",&n);
		result=4*n*n + .25;
		printf("Case %lld: %.2lf\n",c,result);

	}

	return 0;
}
