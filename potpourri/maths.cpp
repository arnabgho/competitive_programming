#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<iostream>
using namespace std;

int  main(){
	int n,len,t;
	std::string val;

	std::getline(std::cin,val);
	
	len=val.length();
	
	if(len>2)
		n=(val[len-1]-48)+(val[len-2]-48)*10;
	else
		n=(val[len-1]-48);
		
	//cout<<n<<endl;
		
	if(n%4==0)
		cout<<"4\n";
	else if(n%4==1)
		cout<<"0\n";
	else if(n%4==2)
		cout<<"0\n";
	else if(n%4==3)
		cout<<"0\n";							
	return 0;
}