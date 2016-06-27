#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

int arr[10];
int main(){
	int a,b,c,maxim,i;
	cin>>a>>b>>c;
	arr[0]=a+b+c;
	arr[1]=a*b*c;
	arr[2]=a+b*c;
	arr[3]=a*b+c;
	arr[4]=(a+b)*c;
	arr[5]=a*(b+c);
	maxim=0;
	for(i=0;i<6;i++)
		maxim=max(maxim,arr[i]);
	cout<<maxim<<endl;
	return 0;
}