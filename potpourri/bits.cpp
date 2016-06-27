#include <stdio.h>
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <math.h>

using namespace std;

typedef long long int LL;
typedef double D;
LL maxbits(LL l,LL r){
	D d_b;
	LL b,power;
	d_b=log2(r);
	b=(LL)d_b;
	// cout<<"b= "<<b<<endl;
	// cout<<"l= "<<l<<" r= "<<r<<endl;

	power=pow(2,b);
	// cout<<"Power "<<power<<endl;
	if(l==r) return l;
	else if(l>=power){
		// cout<<"HI 1\n";
		// cout<<"2^b: "<<power<<endl;
		return power+maxbits(l-power,r-power);
	}
	else if(r>=2*power-1){
		// cout<<"HI 2\n";
		return 2*power-1;
	}
	else{
		// cout<<"HI 3\n";
		return power-1;
	}
}


int main(){
	LL n,l,r;
	cin>>n;
	while(n--){
		cin>>l>>r;
		cout<<maxbits(l,r)<<endl;
	}
	return 0;
}