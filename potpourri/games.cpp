#include<stdio.h>
#include<stdlib.h>
#include<iostream>

using namespace std;

struct dress{
	int home;
	int away;
};

int main(){
	
	int i,j,n,res;
	struct dress * arr;
	scanf("%d",&n);
	arr=(struct dress *)calloc(n,sizeof(struct dress));
	for(i=0;i<n;i++){
		scanf("%d %d",&arr[i].home,&arr[i].away);
	}
	res=0;
	for(i=0;i<n;i++){
		
		for(j=0;j<n;j++){
			if(i==j)
				continue;
			else{
					if(arr[i].away==arr[j].home)
						res++;
			}
		}
	}
	printf("%d\n",res);
	return 0;
}	
