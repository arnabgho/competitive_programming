#include <stdio.h>
#include <iostream>
#include <stdlib.h>

using namespace std;

int arr[101];
int main(){

	int i,n,a,b,k;
	cin>>n>>a>>b;

	for(i=1;i<=a;i++){
		cin>>k;
		arr[k]=1;
	}
	for(i=1;i<=b;i++){
		cin>>k;
		if(!arr[k])
			arr[k]=2;
	}
	for(i=1;i<=n;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	return 0;
}