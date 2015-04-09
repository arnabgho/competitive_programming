#include<stdio.h>
#include<stdlib.h>

void swap(long long int *a,long long int *b){
	long long int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}

long long int  partition(long long int *arr,long long int left,long long int right){
	
	long long int i,j,pivot;
	pivot=arr[left];
	i=left+1;
	for(j=left+1;j<=right;j++){
		
		if(arr[j]<=pivot){
			swap(&arr[j],&arr[i]);
			i++;
		}
		
	}
	swap(&arr[left],&arr[i-1]);
	return i-1;
}

void quickSort(long long int *arr,long long int length){
	long long int pos;
	if (length == 1||length==0)
		return;
	else{
		pos=partition(arr,0,length-1);
		quickSort(arr,pos);
		quickSort(arr+pos+1,length-pos-1);
		
	}
	
	
}



/*
int main(){
	
	long long int n,c,*arr;
	scanf("%lld",&n);
	arr=(long long int *)calloc(n,sizeof(long long int ));
	c=0;
	while(c<n){
		scanf("%lld",&arr[c]);	
		c++;
	}
	quickSort(arr,n);
	for(c=0;c<n;c++)
		printf("%lld\n",arr[c]);
	return 0;
}
*/

int main(){

	long long int n,*arr,*b,*c,temp,flag,maxN,i,j,maxC;
	long long int *dig;
	while(scanf("%lld",&n)!=EOF){
		arr=(long long int *)calloc(n,sizeof(long long int));
		for(i=0;i<n;i++)
			scanf("%lld",&arr[i]);

		quickSort(arr,n);
		b=(long long int *)calloc(n,sizeof(long long int));
		c=(long long int *)calloc(n,sizeof(long long int));
		for(i=0;i<n;i++){
			b[i]=arr[i];
			c[i]=1;
		}
		for(i=n-1;i>=0;i--){
			temp=arr[i];
			dig=(long long int *)calloc(10,sizeof(long long int));
			while(temp>0){
				dig[temp%10]=1;
				temp/=10;
			}
			for(j=n-1;j>=0;j--){
				flag=0;
				if(i==j)
					continue;
				else{
						temp=arr[j];
						while(temp>0){
							if(dig[temp%10]==1){
								flag=1;		
								break;
							}
							temp/=10;						
						}			
					}
				
				if(flag!=1){
					c[i]=c[i]+1;
					b[i]=b[i]+arr[j];
				}
			}
			free(dig);
		}
		maxN=0;
		maxC=0;
		for(i=0;i<n;i++){
			if(b[i]>maxN)
				maxN=b[i];
		}
		for(i=0;i<n;i++){
			if(b[i]==maxN){
				if(c[i]>maxC)
					maxC=c[i];
			}	
		}
		printf("%lld\n%lld\n",maxC,maxN);
		free(b);
		free(c);
	}
	return  0;
}



