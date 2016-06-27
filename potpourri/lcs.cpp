#include<stdio.h>
#include<iostream>
using namespace std;

long long int maxi(long long int a,long long int b ){
	return a>b ? a:b;
}

long long int arr[100000];
long long int lcs[100000];
int main(){

        int i,n;
        long long int max,here;
        scanf("%d",&n);
        for (i=1;i<=n;i++)
                scanf("%lld",&arr[i]);

        max=0;
		here=0;
        for(i=1;i<=n;i++){
        		if(here>=0)
               		here=here+arr[i];
               	else
               		here=arr[i];	
                max=maxi(max,here);
                //printf("here :%lld\n",here);
        }
        
        printf("%lld\n",max);

        return 0;
}

