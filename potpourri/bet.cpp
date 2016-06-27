#include <stdio.h>
#include <iostream>

using namespace std;

int arr[5];
int main(){
	int i,sum=0;
	for(i=0;i<5;i++){
		cin>>arr[i];
		sum+=arr[i];
	}
	if(sum%5==0 && sum>0)
		cout<<sum/5<<endl;
	else
		cout<<"-1\n";
}