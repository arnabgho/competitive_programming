#include<stdio.h>
#include<stdlib.h>
#include<iostream>

using namespace std;
long long int a[100001];
long long int b[100001];
int main(){
	long long int i,n;
	cin>>n;
	long long int happy=0;
	for(i=1;i<=n;i++){
		cin>>a[i];	
	}

	for(i=1;i<=n;i++){
		cin>>b[i];	
	}

	for(i=1;i<=n;i++){
		if(2*a[i]<b[i]){
			happy--;		
		}
		else{
			if(b[i]%2==0){
				happy+=(b[i]*b[i])/4;
			}	
			else{
				happy+=(b[i]*b[i]-1)/4;
			}		}
	
	}
	cout<<happy;
	return 0;
}
