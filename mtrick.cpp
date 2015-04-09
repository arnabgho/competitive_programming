#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<iostream>

using namespace std;

long long int max(long long int a,long long int b){
	return a>b ? a:b;
}
long long int min(long long int a,long long int b){
	return a<b ? a:b;
}

long long int mul(long long int A,long long int B,long long int C){
	long long int j,k,x,y,pow,res,dig,temp;
	x=max(A,B);
	y=min(A,B);
	pow=1;
	k=1;
	res=0;
	while(x>0){
		dig=x%2;
		x/=2;

		if(dig==1){
			temp=y%C;
			for(j=1;j<k;j++){
				temp=(temp*2)%C;	
			}
			res=(res+temp)%C;
		}
		k++;
	}
	//printf("%lld",res);
	return res;
}


long long int L[1001];
char s[1001];
int main(){
	long long int i,c,t,N,A,B,C,j,temp;
	c=0;
	scanf("%lld",&t);
	while(c++<t){
		scanf("%lld",&N);
		for(i=1;i<=N;i++){
			scanf("%lld",&L[i]);		
		}
		scanf("%lld %lld %lld",&A,&B,&C);
		scanf("%s",s+1);
		//printf("%s",s+1);
		for(i=1;i<=N;i++){
			if(s[i]=='A'){
				for(j=i;j<=N;j++)
					L[j]=(L[j]+(A%C))%C;					
			}
			else if(s[i]=='M'){
				for(j=i;j<=N;j++)
					L[j]=mul(L[j],B,C);							
			}
			else if(s[i]=='R'){
				for(j=i;j<=(i+N)/2;j++){
					temp=L[N-j+i];
					L[N-j+i]=L[j];
					L[j]=temp;	
				}	
			}
		
		}
		for(i=1;i<=N;i++)
			printf("%lld ",L[i]%C);
		printf("\n");	
	}
	return 0;
}
