#include <stdio.h>
#include <iostream>

using namespace std;

int main(){
	long long int n,m,k_max,k_min,a,b,c;
	cin>>n>>m;
	k_max=(n-m+1)*(n-m);
	k_max/=2;
	a=n/m;
	b=n%m;
	c=m-b;

	//cout<<"a: "<<a<<" b : "<<b<<endl; 
	k_min=c*(a*(a-1))/2 + b*((a)*(a+1))/2;
	cout<<k_min<<" "<<k_max<<endl;
	return 0;
}	