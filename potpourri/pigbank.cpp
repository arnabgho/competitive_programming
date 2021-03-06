#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<limits.h>

using namespace std;

long long int arr[501][2];
long long int res[10001];

long long int min(long long int a,long long int b){
	return (a<b) ? a:b;
}

void init(long long int weight){
	long long int i;
	for(i=1;i<=weight;i++)
		res[i]=LONG_LONG_MAX;
}

int main(){

	long long int mini,c,t,e,f,n,weight,i,flag,k,j;	
	c=0;
	scanf("%lld",&t);
	while(c++<t){
		scanf("%lld %lld",&e,&f);
		weight=f-e;
		init(weight);
		res[0]=0;
		scanf("%lld",&n);
		mini=LONG_LONG_MAX;
		for(i=1;i<=n;i++){
			scanf("%lld %lld",&arr[i][0],&arr[i][1]);
			if(arr[i][1]<mini){
				mini=arr[i][1];
			}			
		}
		printf("%lld\n",mini);
		for(j=1;j<mini;j++){
			res[j]=LONG_LONG_MAX;			
		}
		for(j=mini;j<=weight;j++){
			flag=0;
			for(k=1;k<j;k++){
				if(res[k]==LONG_LONG_MAX || res[j-k]==LONG_LONG_MAX)
					continue;
				else{
						flag=1;
						res[j]=min(res[j],res[k]+res[j-k]);						
				}			
			}
			for(k=1;k<=n;k++){
				if(j%arr[k][1]==0){
					flag=1;
					res[j]=min(res[j],(j*arr[k][0])/arr[k][1]);
				}
			}
			if(flag==0)
				res[j]=LONG_LONG_MAX;
		}	
		for(i=1;i<=weight;i++)
			printf("%lld\n",res[i]);
	
		printf("%lld\n",LONG_LONG_MAX);
		if(res[weight]!=LONG_LONG_MAX)	
			printf("The minimum amount of money in the piggy-bank is %lld.\n",res[weight]);
		else
			printf("This is impossible.\n");
	}
	
	return 0;
}
