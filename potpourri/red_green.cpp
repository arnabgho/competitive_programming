#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//#include <math>
#include <iostream>

using namespace std;
#define N 1000000007;
long long int recur(int r,int g,int h){
	long long int ans=0;
	if(h==0){
		//cout<<"Hi\n";
		return 1;
	}
	if(r<h && g<h && h>0)
		return 0;
	if(g>=h && h>0){
		//cout<<"g > h\t"<<"g \t"<<g<<" h\t"<<h<<endl;
		ans=(ans+recur(r,g-h,h-1))%N;
	}
	if(r>=h && h>0){
		//cout<<"r > h\t"<<"r \t"<<r<<" h\t"<<h<<endl;
		ans=(ans+recur(r-h,g,h-1))%N;
	}
	return ans;
}

int main(){
	double com;
	int r,g,sum,h;
	cin>>r>>g;
	sum=r+g;
	com=sqrt(8*sum+1);
	com-=1;
	com/=2;
	h=(int)com;
	//cout<<"h :"<<h<<endl;	
	cout<<recur(r,g,h)<<endl;
	return 0;
}