#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(){
	int a,b,mid,wina,winb,draw;
	scanf("%d %d",&a,&b);
	if(a<b){
		mid=(a+b)/2;
		if(mid*2==a+b){
			draw=1;
			wina=mid-1;
			winb=6-draw-wina;
		}
		else{
			
			draw=0;
			wina=mid;
			winb=6-wina;
		}	
		
	}
	else if(a>b){
		mid=(a+b)/2;
		if(mid*2==a+b){
			draw=1;
			winb=mid-1;
			wina=6-draw-winb;
		}
		else{
			
			draw=0;
			winb=mid;
			wina=6-winb;
		}	


	}
	else{
		wina=0;
		winb=0;
		draw=6;
	}
	printf("%d %d %d\n",wina,draw,winb);

	return 0;
}
