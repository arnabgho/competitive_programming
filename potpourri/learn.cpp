#include <stdio.h>
#include <iostream>

using namespace std;

bool isComposite(int n){

	int i;
	int count=0;
	for(i=2;i<n;i++){
		if(n%i==0){
			count++;
			break;
		}
	}
	if(count>0)
		return true;
	else
		return false;
}

int main(){
	int n,i;
	cin>>n;
	for(i=2;i<n;i++){
		if(isComposite(i)&&isComposite(n-i)){
			cout<<i<<" "<<n-i<<endl;
			break;
		}

	}

	return 0;
}