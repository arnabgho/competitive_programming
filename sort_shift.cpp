#include<stdio.h>
#include<stdlib.h>
#include<iostream>

using namespace std;
int arr[100001];

int main(){

	int n,i,pos,d;
	cin>>n;	
	for(i=0;i<n;i++){
		cin>>arr[i];
	}
	pos=-1;
	for(i=0;i<n;i++){
		d=arr[(i+1)%n]-arr[i%n];
		//printf("i=%d d=%d\n",i,d);
		if(d<0 && pos==-1){
			pos=n-(i+1);
		}
		else if(d<0 && pos!=-1){
			cout<<"-1\n";
			pos=-2;
			break;
		}
	}
	if(pos>=0)
	 cout<<pos<<endl;
	if(pos==-1)
		cout<<"0\n" ;
	
	return 0;
}
