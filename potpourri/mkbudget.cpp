#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<math.h>
#include<string.h>
#include<limits.h>
using namespace std;

long long int arr[31][25];
long long int worker[30];
long long int MAX=1000000000;

int main(){

	long long int c,i,j,n,hire,sal,fire,max_work,k,val,min;
	scanf("%lld ",&n);
	c=1;
	while(n!=0){

		max_work=0;
		scanf("%lld ",&hire);			
		scanf("%lld ",&sal);					
		scanf("%lld ",&fire);					
		
		for(i=0;i<n;i++){
			scanf("%lld",&worker[i+1]);
			//printf("%lld\n",worker[i+1]);
			if(worker[i+1]>max_work)
				max_work=worker[i+1];
		}
		for(i=1;i<=max_work;i++){
			if(i>=worker[1]){
				arr[i][1]=i*(hire+sal);
			}
			else{
				arr[i][1]=MAX;
			}
		}
		
		//printf("%lld\n",MAX);
		for(j=2;j<=n;j++){
			for(i=1;i<=max_work;i++){
				if(i<worker[j]){
					arr[i][j]=MAX;
				//	printf("%lld\n",MAX);
				}
				else{
					min=MAX;
					for(k=1;k<=max_work;k++){
						
						if(k<=i){

							val=arr[k][j-1]+sal*i+hire*(i-k);
						}
						else{
							val=arr[k][j-1]+sal*i+fire*(k-i);
						}
						//printf("%lld\n",val);
						if(val<min)
							min=val;
					}
					arr[i][j]=min;	
				}
										
				
			//	printf("%lld\n",arr[i][j]);											
									
			}		
		}
		min=MAX;
		for(i=worker[n];i<=max_work;i++){
			val=arr[i][n];
			if(val<min){
				min=val;
			}
			
		}
		

		printf("Case %lld, cost = $%lld\n",c++,min);
		scanf("%lld",&n);
	}
	return 0;
}
