#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

long long int A[10000000];

int main(){

	long long int *A,max,maxi,i,x,nsteps;
	i=0;
//	A=(long long int *)calloc(10000000,sizeof(long long int ));
	A[1]=0;
	A[2]=1;
	for(i=3;i<=1000000;i++)
	{
		x=i;
		nsteps=0;
		while(x!=1){
			
			if(x%2==0){
				if (A[x/2]!=0){
					nsteps+=A[x/2]+1;
					A[i]=nsteps;
					if(A[i]>max){
						maxi=i;
						max=A[i];
					}
					break;
				}
				else{
					x=x/2;
					nstepsarduino programming++;
				}
			}
			else{
				if(A[3*x+1]!=0){
					nsteps+=A[3*x+1]+1;
					A[i]=nsteps;
					if(A[i]>max){
						maxi=i;
						max=A[i];
					}
					break;
				}
				else{
					x=3*x+1;
					nsteps++;
				}
				
			}

		}
		A[i]=nsteps;
		if(A[i]>max){
			maxi=i;
			max=A[i];
		}
	}

	for(i=3;i<10000;i++)	
		A[i]++;	
	
	for(i=0;i<14;i++)
		printf("%lld\n",A[i]);

	
	printf("%lld   \n%lld\n",max,maxi);
}
