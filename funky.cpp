#include<stdio.h>
#include<iostream>
#include<math.h>

using namespace std;

int check(long long int n){
	long long int temp;
	temp=sqrt(8*n+1);
	
	if((8*n+1)-temp*temp == 0)
		return 1;
	else
		return 0;		
		
}

int main(){
	long long int n,i,j,flag,temp;
	flag=0;
	//scanf("%l64d",&n);
	cin>>n;
	for(i=1;i*(i+1)<=n;i++){
		temp=i*(i+1)/2;
		if(check(n-temp)){
			flag=1;
			break;
		}
	}
	if(flag==1)
		printf("YES\n");
	else
		printf("NO\n");
	return 0;
}
