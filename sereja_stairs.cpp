#include<stdio.h>
#include<iostream>
#include<stdlib.h>

using namespace std;

int arr[5001];
int res[20000];
int main(){

	int m,i,temp,max,min,num,tr;
	cin>>m;
	max=0;
	min=5001;
	tr=1;
	for(i=1;i<=m;i++){
		cin>>temp;
		arr[temp]++;
		if(temp>max)
			max=temp;
		if(temp<min)
			min=temp;
		if(arr[temp]>1)
			tr=0;	
	}
	if(tr==0){
	num=1;
	for(i=min;i<=max;i++){	
		if(arr[i]>0){
			arr[i]--;
			res[num]=i;
			num++;
		}	
	}
	for(i=max-1;i>=min;i--){
		if(arr[i]>0){
			arr[i]--;
			res[num]=i;
			num++;
		}	
	}
	num--;
	}
	else{
	num=1;
	for(i=max;i>=min;i--){
		if(arr[i]>0){
			arr[i]--;
			res[num]=i;
			num++;
		}	
	}	
	num--;	
	}
	printf("%d\n",num);
	for(i=1;i<=num;i++)
		printf("%d ",res[i]);
	return 0;

}