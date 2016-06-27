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
struct range{
	long long int s;
	long long int e;
	long long int val;
};
bool cmp1(customer x,customer y){
	if (x.spot<y.spot) return true;
	if (x.spot==y.spot) return x.end<y.end;
	return false;

}

bool cmp2(customer x,customer y){
	return x.end<y.end;
}
struct customer arr[100001];
struct range ran[100001];
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
		st=1;
		curr=arr[1].spot;
		i=1;
		ran[1].s=st;
		ran[1].val=curr;
		j=1;		
		while(i<=N-1){
			i++;
			if(arr[i].spot!=curr){
				ran[j+1].s=i;
				ran[j].e=i-1;
				ran[j+1].val=arr[i].spot;
				curr=arr[i].spot;
				j++;	
			}	
			
			else{
				continue;
			}		
		}
		ran[j].e=N;
		ran[j].val=arr[N].spot;
		j++;
		/*
		for(i=1;i<j;i++){
			printf("%lld %lld %lld\n",ran[i].s,ran[i].e,ran[i].val);
		}
		*/
		num=j;
		for(i=1;i<num;i++){
			//sort(arr+ran[i].s,arr+ran[i].e+1,cmp2);
			
			total+=1;
			prev=arr[ran[i].s].end;
			for(j=ran[i].s+1;j<=ran[i].e;j++){
				if(arr[j].start>=prev){
					total+=1;
					prev=arr[j].end;
				}
				else{
					continue;
				}
			}
		}
		printf("%lld\n",total);
	}

	return 0;
}
