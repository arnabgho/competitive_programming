#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<stdio.h>

long long int  



int main(){

	long long int i,k,*A,*B,result;
	
	scanf("%lld",&k);
	A=(long long int *)calloc(k,sizeof(long long int ));
	B=(long long int *)calloc(k,sizeof(long long int));
	for(i=0;i<k;i++)
		scanf("%lld",&A[i]);
	for(i=0;i<k;i++)
		scanf("%lld",&B[i]);

	result=gaussMult(A,B,k);

	return 0;
}
