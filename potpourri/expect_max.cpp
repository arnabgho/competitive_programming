#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<math.h>

using namespace std;

int main(){
	int i;
	double m,n,res;
	cin>>m>>n;
	res=0;
	for(i=1;i<=m;i++){
		res+=(pow((i),n+1)-1)/(pow(m,n));
	}
	cout<<res<<endl;
	return 0;
}

