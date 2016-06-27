#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{

	long long int c,t,n,k_3,k_5,k_15,ans;
	c=0;	
	scanf("%lld",&t);
	while(c++<t){
		scanf("%lld",&n);
		if(k_3%3!=0)
			k_3=n/3;
		else
			k_3=n/3-1;		
		if(k_5%5!=0)	
			k_5=n/5;
		else
			k_5=n/5-1;
		if(k_15%15!=0)
			k_15=n/15;
		else
			k_15=n/15-1;
		ans=3*k_3*(k_3+1)/2 + 5*k_5*(k_5+1)/2+15*k_15*(k_15+1)/2;
		printf("%lld\n",k_3);
		printf("%lld\n",k_5);
		printf("%lld\n",k_15);

		printf("%lld\n",ans);
	}

	return 0;
}
