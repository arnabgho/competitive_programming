#include <iostream>
#include <string>
#include <math.h>
#include<stdio.h>
using namespace std;


void ableToGet(int x, int y){
		long long int res,pow_3,i,k,xa,ya,j,temp,bit;
		//string result;
		float p,q;
		p=x;
		q=y;
		if(x==0 && y==0){
			printf ("Possible\n");
			return;
		}	
		k=log(p+q)/log(3.0);
		xa=0;
		ya=0;res=0;
		printf("%lld\n",k);
		
		for(i=0;i<pow(2,k+1);i++){
			temp=i;pow_3=1;
			xa=0;
			ya=0;
			for(j=1;j<=k+1;j++){
				bit=temp%2;
				if(bit==1){
					xa+=pow_3;
				}	
				else if(bit==0){
					ya+=pow_3;
				}
				temp=temp/2;
				pow_3*=3;				
			}
			printf("%lld %lld\n",xa,ya);
			if(xa==x && ya==y){
				res=1;
				break;
			}
		}
		/*
		if(res==1)
			result= "Possible";
		else
			result= "Impossible";	
		printf("%s\n",result); 
		*/	
		if(res==1)
			printf("Possible\n");
		else
			printf("Impossible\n");
	}
	
int	main(){

	 int x,y;
	scanf("%d %d",&x,&y);
	ableToGet(x,y);
}	
