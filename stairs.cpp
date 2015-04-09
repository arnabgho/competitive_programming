#include <stdio.h>
#include <iostream>

using namespace std;

int main(){

	int i,n,m,ans;
	cin>>n>>m;
	ans=-1;
	for(i=n/2;i>=0;i--){
		if((n-i)%m==0){
			ans=n-i;
			break;
		}
	}
	cout<<ans<<endl;
	return 0;
}