#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<stdlib.h>
using namespace std;
	
bool cmp(int a,int b){
	return a<b;
}
int main(){
	int i,*arr,n;
	scanf("%d",&n);
	arr=(int *)calloc(n,sizeof(int));
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	sort(arr,arr+n,cmp);
	for(i=0;i<n;i++){
		printf("%d\n",arr[i]);
	}

	return 0;
}