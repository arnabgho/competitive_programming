#include<stdio.h>
#include<stdlib.h>
#include<iostream>

using namespace std;

int main(){
	int i,p,q,n,res=0;
	cin>>n;
	for(i=1;i<=n;i++){
		cin>>p>>q;
		if(q-p>=2)
			res++;
	}
	cout<<res<<endl;

	return 0;
}