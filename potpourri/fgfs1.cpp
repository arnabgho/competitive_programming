#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<iostream>
#include<algorithm>
using namespace std;

struct customer{
	long long int start;
	long long int end;
	long long int spot;
};
bool cmp1(customer x,customer y){
	if (x.spot<y.spot) return true;
	if (x.spot==y.spot) return x.end<y.end;
	return false;

}

struct customer arr[100001];
int main(){

	long long int T,N,K,c,i,st,en,curr,j,total,prev,num,k;
	c=0;
	scanf("%lld",&T);
	while(c++<T){
		total=0;
		scanf("%lld %lld",&N,&K);	
		if(N==0){
			printf("0\n");
			continue;
		}
		for(i=1;i<=N;i++){
			scanf("%lld %lld %lld",&arr[i].start,&arr[i].end,&arr[i].spot);
		}
		sort(arr+1,arr+N+1,cmp1);
		/*
		printf("\n \n");
	
		for(i=1;i<=N;i++)
			printf("%lld %lld %lld\n",arr[i].start,arr[i].end,arr[i].spot);
		printf("\n \n");
		*/
		
		/*
		for(i=1;i<j;i++){
			printf("%lld %lld %lld\n",ran[i].s,ran[i].e,ran[i].val);
		}
		*/
		curr=arr[1].spot;
		prev=arr[1].end;
		total+=1;
		for(i=2;i<=N;i++){
			//sort(arr+ran[i].s,arr+ran[i].e+1,cmp2);	
			
			if(curr==arr[i].spot){
				if(arr[i].start>=prev){
					prev=arr[i].end;
					total+=1;
					
				}
				else{
					continue;
				}
			}
			else{
				curr=arr[i].spot;
				prev=arr[i].end;
				total+=1;
			}
		}
		printf("%lld\n",total);
	}

	return 0;
}
