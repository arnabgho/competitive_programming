#include<stdio.h>
#include<stdlib.h>
#include<iostream>

using namespace std;

int main(){



	int n,i,j,k,rev;
	cin>>n;
	k=(n-1)/2;
	rev=0;
	for(i=1;i<=n;i++){
	
		for(j=0;j<k;j++){
			cout<<"*";	
		}
		for(j=0;j<n-2*k;j++){
			cout<<"D";
		}
		for(j=0;j<k;j++){
			cout<<"*";	
		}
		if (k==0){
			rev=1;
		}
		if (rev==0){
			k--;
		}
		else{
			k++;
		}
		cout<<endl;
	}


	return 0;
}