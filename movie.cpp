#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<algorithm>

using namespace std;
static long long int N=100000;

long long int arr[200001][2];

int main(){
		
	long long int n,m,top,num,p;

	long long int i,j,c,t;
	scanf("%lld",&t);
	c=0;
	while(c++<t){	
	scanf("%lld %lld",&n,&m);
	for(i=1;i<=n;i++){
		arr[n-i+1][0]=i;
		arr[n-i+1][1]=1;
	}
	
	top=n;
	for(i=1;i<=m;i++){
		scanf("%lld",&p);
		num=0;
		if(arr[top][0]==p && arr[top][1]==1)
			num=0;
		else{
			top=top+1;
			arr[top][0]=p;
			arr[top][1]=1;
			for(j=top-1;j>=1;j--){
				if(arr[j][0]==p && arr[j][1]==1){
					arr[j][1]=0;
					break;
				}
				else{
					num+=arr[j][1];
				}
			}
		}
		if(i!=m){
			printf("%lld ",num);
		}
		else{
			printf("%lld\n",num);
		}		
	}
	}
	return 0;
}