#include<stdio.h>
#include<stdlib.h>
#include<iostream>

using namespace std;

int main(){

	int n,i,j;
	cin>>n;
	cout<<(n*n+1)/2<<endl;
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			if((i+j)%2==0)
				cout<<"C";
			else
				cout<<".";
			}
		cout<<endl;
	}
	return 0;
}
