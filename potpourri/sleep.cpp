#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
int main(){
	char dummy;
	int h1,h2,m1,m2,t1,t2,hr,mr,res;
	cin>>h1>>dummy>>m1;
	cin>>h2>>dummy>>m2;
	t1=h1*60+m1;
	t2=h2*60+m2;
	if(t1>=t2){
		res=t1-t2;
		hr=res/60;
		mr=res%60;
	}	
	else if(t1<t2){
		if(t2-t1<=1440)
			res=1440+t1-t2;
		else
			res=2880+t1-t2;	
		hr=res/60;
		mr=res%60;
	}	
	if(hr<10 && mr<10){
		cout<<'0'<<hr<<":"<<'0'<<mr<<endl;	
	}
	else if(hr<10 && mr>=10){
		cout<<'0'<<hr<<":"<<mr<<endl;			
	}
	else if(hr>=10 && mr<10){
		cout<<hr<<":"<<'0'<<mr<<endl;			
	}
	else if(hr>=10 && mr>=10){
		cout<<hr<<":"<<mr<<endl;
	}
	return 0;
}
