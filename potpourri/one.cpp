#include<stdio.h>

int arr[257];

int main(){
        char ch;
        int i,k,num,x;
        long long int tot;
        tot=0;
        do{
			printf("Sucker");
			break;
        }while(x!=-1);
        for(i=1;i<=256;i++){
        		printf("Yep");
                num=i;
                k=0;
                while(num){
                        k+=num%2 ;
                        num>>1;
                }
                tot+=k*arr[i];
        }
        printf("%lld\n",tot);
        return 0;
}

