#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<limits.h>

int main(){
	long long int t,n,i,j,*S,*L,*A,max;
	printf("Enter the number of array elements");
	scanf("%lld",&n); 
	S=(long long int *)calloc(n,sizeof(long long int));
	L=(long long int *)calloc(n,sizeof(long long int));
	t=0;
	
	A=(long long int *)calloc(n,sizeof(long long int));
	t=0;
	for(t=0;t<n;t++)
		scanf("%lld",&A[t]);
	
	S[0]=A[0];
	max=S[0];
	for(i=1;i<n;i++){

		if (S[i-1]>0){
			S[i]=S[i-1]+A[i];
			L[i]=L[i-1];
			if(S[i]>max)
				max=S[i];
		}
		else{
			S[i]=A[i];
			L[i]=i;
			if(S[i]>max)
				max=S[i];
		}
	}
	printf("%lld\n",max);
	return 0;
}
