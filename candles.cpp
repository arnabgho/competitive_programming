#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<iostream>

using namespace std;

int main(){

	long long int a,b,spent,rem;
	
	cin>>a>>b;
	spent=0;
	rem=0;
	spent=a;
	while(a>0){			
		rem+=a%b;
		a=(a)/b;	
		spent+=a;
		//cout<<rem<<"   "<<spent<<endl;
		if(a==0 && rem>=b){
			a=rem;
			rem=0;
		}	
		else if(a==0 && rem<b){
			break;
		}
	}
	cout<<spent<<endl;
	return 0;
}
