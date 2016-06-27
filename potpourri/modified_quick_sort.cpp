#include<stdio.h>
#include<stdlib.h>

struct cont{
	char  name[10];
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
	
	long long int n,c;	
	struct cont * arr;
	scanf("%lld",&n);
	arr=(struct cont *)calloc(n,sizeof(struct cont));
	c=0;
	while(c<n){
		scanf("%s",arr[c].name);	
		scanf("%lld",&arr[c].val);
		c++;
	}
	quickSort(arr,n);
	for(c=0;c<n;c++){
		printf("%s\n",arr[c].name);		
		printf("%lld\n",arr[c].val);
	}
	return 0;
}
