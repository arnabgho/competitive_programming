#include<stdio.h>
#include<stdlib.h>
#include<math.h>
//#define G 9.806;
int main(){
long long int c,t;
double result,G,s,u;
c=0;
G=9.806;
scanf("%lld",&t);

while(c++<t){

	scanf("%lf %lf",&s,&u);
	//printf("%lf %lf\n",s,u);
	if(G*s>u*u)
		printf("Scenario #%lld: -1\n",c);
	else{
		result=45.0*asin((G*s)/(u*u))/acos(0.0);
		printf("Scenario #%lld: %.2lf\n",c,result);
	}
}
return 0;
}
