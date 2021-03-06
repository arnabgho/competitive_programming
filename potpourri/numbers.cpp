#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>

using namespace std;

struct cont{
	char  name[20];
	long long int val;
};


void swap(struct cont *a,struct cont *b){
	struct cont temp;
	temp=*a;
	*a=*b;
	*b=temp;
}

long long int  partition(struct cont *arr,long long int left,long long int right){
	
	long long int i,j,pivot;
	pivot=arr[left].val;
	i=left+1;
	for(j=left+1;j<=right;j++){
		
		if(arr[j].val<=pivot){
			swap(&arr[j],&arr[i]);
			i++;
		}
		
	}
	swap(&arr[left],&arr[i-1]);
	return i-1;
}

void quickSort(struct cont *arr,long long int length){
	long long int pos;
	if (length == 1||length==0)
		return;
	else{
		pos=partition(arr,0,length-1);
		quickSort(arr,pos);
		quickSort(arr+pos+1,length-pos-1);
		
	}
	
	
}




int main(){
	
	long long int n,c,t,te,t1,t2,i,num;	
	char temp[20],temp1[6];
	struct cont * arr;
	t=0;
	scanf("%lld\n",&te);
	
	while(t++<te){
		scanf("%lld\n",&n);
		arr=(struct cont *)calloc(n,sizeof(struct cont));
		c=0;
		while(c<n){
			scanf("%s",arr[c].name);
			scanf("%lld",&arr[c].val);
		/*
			while(temp[i]!=' '){
				temp1[t1]=temp[i];
				printf("%c\n",temp[i]);
				t1++;
				i++;
			}
			i++;
		*/
			
			//scanf("%s",arr[c].name);	
			//scanf("%lld",&arr[c].val);
			c++;
		}
		quickSort(arr,n);
		if(arr[0].val!=arr[1].val){
			printf("%s\n",arr[0].name);
			continue;
		}
		else {		
			for(c=1;c<n-1;c++){
				if(arr[c].val!=arr[c-1].val && arr[c].val!=arr[c+1].val){
					printf("%s\n",arr[c].name);		
					break;
				}
			}
			if(c==n-1){
				if(arr[n-1].val!=arr[n-2].val){
					printf("%s\n",arr[n-1].name);
				}
				else{
					printf("Nobody wins.\n");
				}
			}
		}
		free(arr);
	}
	return 0;
}
