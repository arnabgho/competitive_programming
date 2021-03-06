#include<stdio.h>
#include<stdlib.h>
#include<map>
#include<iostream>

using namespace std;
std :: map<long long int , long long int> coins;

long long int max(long long int a,long long int b){
	return a>b ? a:b;
}

long long int max_val(long long int n){
	long long int a,b,c;
	
	a=coins[n/2];
	b=coins[n/3];
	c=coins[n/4];
	
		//printf("A=%lld ",a);
		
		if(n==0)
			return 0;
		
		if (a==0){
			a=max_val(n/2);
			coins[n/2]=a;
		}
		if(b==0){
			b=max_val(n/3);
			coins[n/3]=b;
		}
		if(c==0){
			c=max_val(n/4);
			coins[n/4]=c;
		}
	
	
		return max(a+b+c,n);

}

/*
int main(){
	long long int n;
	while(1){
		cin>>n;
		cout<<max_val(n)<<endl;
	}	
}

*/
int main()
{
	long long int ch,ch1,n,flag=1;
//arr=calloc(500000001,sizeof(long long int));
	while(!(flag==0))
	{
		ch=getchar();
		ch1=ch;
		if(ch==-1)
		{	
			flag=0;
			break;
		}
		else
			ungetc(ch,stdin);
		if(ch1!=-1)
			scanf("%lld\n",&n);
		if(ch1!=-1)
			printf("%lld\n",max_val(n));
		else
			break;
	}
	return 0;
}

