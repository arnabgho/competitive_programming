#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<iostream>

using namespace std;

int main(){

	long long int n,temp;
	char * arr[10]={"O-|-OOOO","O-|O-OOO","O-|OO-OO","O-|OOO-O","O-|OOOO-","-O|-OOOO","-O|O-OOO","-O|OO-OO","-O|OOO-O","-O|OOOO-"};
	//scanf("%lld",&n);
	cin>>n;
	while(n>0){
		temp=n%10;
		printf("%s\n",arr[temp]);
		n=n/10;
	}

	return 0;

}
