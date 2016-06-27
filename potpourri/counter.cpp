#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

long long int gcd(long long int a,long long int b){
	if(b==0)
		return a;
	else return gcd(b,a%b);
}

int main(){
	long long int l,r,pos=0,i,j,k;
	cin>>l>>r;
	long long int a=-1,b=-1,c=-1;

	///cout<<"gcd : "<<gcd(900000000000000021,900000000000000009)<<endl;

	for(i=l;i<=r-2 && !pos;i++){
		for(j=i+1;j<=r-1 && !pos;j++){
			for(k=j+1;k<=r && !pos;k++){
				if(gcd(j,i)==1 && gcd(k,j)==1 && gcd(k,i)!=1){
					a=i;b=j;c=k;
					pos=1;break;
				}
			}
		}
	}
	if(pos)
		cout<<a<<" "<<b<<" "<<c<<endl;
	else
		cout<<"-1\n";
	return 0;
}