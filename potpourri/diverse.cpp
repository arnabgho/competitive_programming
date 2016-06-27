#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

int main(){

	int n,k,i;
	int left,right;
	cin>>n>>k;

	left=1;
	right=n;
	for(i=1;i<=k-1;i++){
		(i%2==0)? cout<<right--<<" " : cout<<left++<<" ";
	}
	if(k%2==0){
		for(i=right;i>=left;i--)
			cout<<i<<" ";
	}
	else{
		for(i=left;i<=right;i++)
			cout<<i<<" ";
	}

	return 0;
}