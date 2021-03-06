#include<stdio.h>
#include<stdlib.h>
#include<math.h>

//long long int *D,*E;
//D=(long long int *)calloc(100,sizeof(long long int));
//E=(long long int *)calloc(100,sizeof(long long int));

long long int* gaussMultiply(long long int * A, long long int * B,long long int * C,long long int k,long long int shift){
	long long int i,*D,*E,*F,*G,*H,*I,*J;
	D=calloc(long long int ,sizeof(2*k));
	//E=calloc(long long int ,sizeof(k));
	G=calloc(long long int ,sizeof(2*k));
	H=calloc(long long int ,sizeof(2*k));
	I=calloc(long long int ,sizeof(2*k));
	J=calloc(long long int ,sizeof(2*k));
	for(i=0;i<k/2;i++)
	{
		H[i]=A[i]+B[i];
	}
	for(i=k/2;i<k;i++)
	{
		I[i]=A[i]+B[i];
	}
	if(k>=1){
	 	E=gaussMultiply(A+k/2,B+k/2,C,k/2);
		F=gaussMultiply(A,B,C,k/2);
		J=gaussMultiply(H,I,C,k/2);
		for(i=0;i<k;i++){
			G[i]=J[i]-E[i]-F[i];
		}
		for(i=0;i<k;i++)
		{
			C[shift+i]+=E[i];
			C[shift/2+i]+=G[i];
			C[i]+=F[i];
		}
	}
		
	for(i=0;i<2*k;i++)
		D[i]=C[i];
	return &D;
}




int main(){

	long long int i,k,*A,*B,*C;
	scanf("%lld",&k);
	A=(long long int *)calloc(k,sizeof(long long int));
	B=(long long int *)calloc(k,sizeof(long long int));
	C=(long long int *)calloc(k,sizeof(long long int));
	for(i=1;i<=k;i++)
		scanf("%lld",&A[k-i]);

	for(i=1;i<=k;i++)
		scanf("%lld",&B[k-i]);

	gaussMultiply(A,B,C,k);

	return 0;
}
