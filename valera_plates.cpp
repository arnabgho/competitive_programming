#include<stdio.h>
#include<stdlib.h>
#include<iostream>

using namespace std;

int main(){
	
	long long int i,day,na,nb,a,b,dummy,res;
	a=0;b=0;
	
	cin>>day>>na>>nb;
	for(i=0;i<day;i++){	
			
		cin>>dummy;
		if(dummy==1)
			a++;
		else
			b++;
	}

	if(b>=nb)
		res= a-na + b-nb;
	else if(a<na && b<nb )
		res=0;
	else if(a>=na && b<nb)
		res=a-na;


	cout<<res<<'\n';
	return 0;
}
