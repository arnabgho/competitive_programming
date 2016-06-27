#include<stdio.h>
#include<stdlib.h>
#include<iostream>

using namespace std;

int main(){
	
	int n,i,flag=0;
	int arr[11]={4,7,47,74,447,474,477,744,747,774,777};
	
	cin>>n;
	for(i=0;i<11;i++){
		if(n%arr[i]==0)
			flag=1;

	}
	if(flag==1)
		printf("YES\n");
	else
		printf("NO\n");
	return 0;
}
