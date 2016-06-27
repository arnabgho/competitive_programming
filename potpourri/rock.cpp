#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>
#include <map>
using namespace std;

long long int pow_3[100];

std::map<long long int ,char> mymap;
std::map<long long int ,char>::iterator it;
void pow_of_3(){
	long long int i,n;
	n=1;i=0;
	while(i<=26){
		pow_3[i]=n;
		i++;
		n*=3;
	}
}



char game(long long int n){
	long long int p,dp;
	double power;
	char ch;
	if(n==1)
		return 'R';
	else if(n==2)
		return 'P';
	else if(n==3)
		return 'S';
	else{
		power=log(n)/log(3);
		p=(long long int)power;
		//cout<<"Power: "<<power<<" p :"<<p<<endl;
		if(pow_3[p]==n){
			dp=pow_3[p-1];
		}
		else
			dp=pow_3[p];

		it=mymap.find(n-dp);
		if(it!=mymap.end()){
			ch=mymap[n-dp];			
		}
		else{
			//map.put(n-dp,game(n-dp));
			mymap[n-dp]=game(n-dp);
			ch=mymap[n-dp];
		}

		if(ch=='P')
			return 'S';
		else if(ch=='R')
			return 'P';
		else if(ch=='S')
			return 'R';

	}

}


int main(){

	long long int n;
	char ans;
	
	cin>>n;
	pow_of_3();
	while(n!=0){
		ans=game(n);
		
		if(ans=='P')
			cout<<'S'<<endl;
		else if(ans=='R')
			cout<<'P'<<endl;
		else if(ans=='S')
			cout<<'R'<<endl;
		//cout<<ans<<endl;
		cin>>n;
	}

}