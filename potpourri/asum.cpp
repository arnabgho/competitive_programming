#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
int arr[100001];
int main(){
	int c,t,n,i,max,count;
	scanf("%d",&t);
	max=INT_MIN;
	while(c++<t){
		scanf("%d",&n);
		for(i=1;i<=n;i++){
			scanf("%d",&arr[i]);
			if(arr[i]>max)
				max=arr[i];
		}		
		for(i=1;i<=n;i++){
			if(max==arr[i])
				count++;
		}
		if(max<0)
			printf("1\n");
		else 	
			printf("%d",count+1);
	}	
	
	return 0;
}
