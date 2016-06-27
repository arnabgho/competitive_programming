#include<stdio.h>
#include<math.h>
#include<stdlib.h>

using namespace std;

int main(){
	int c,T;
	double L,D,S,C,lres,lL;
	c=0;
	scanf("%d",&T);
	while(c++<T){
		scanf("%lf %lf %lf %lf",&L,&D,&S,&C);
		lres=log10(S)+(D-1)*log10(1+C);
		lL=log10(L);
		if(lres>=lL)
			printf("ALIVE AND KICKING\n");
		else
			printf("DEAD AND ROTTING\n");

	}


	return 0;
}
