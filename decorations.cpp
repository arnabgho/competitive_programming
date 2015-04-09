#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>

using namespace std;

bool isPossible(long long int r,long long int g,long long int b,long long int k){
	return !( ((r-2*k)>0 && (b+g<k)) || ((b-2*k)>0 && (r+g<k)) || ((g-2*k)>0 && (b+r<k)) );
}

long long int bin(long long int r,long long int g,long long int b,long long int minim,long long int maxim){
	long long int mid=(minim+maxim)/2;
	if(minim>maxim)	return 0;
	if(isPossible(r,g,b,mid)){
		//cout<<"Hi\n";
		if(mid+1<=maxim)
			return max(mid,bin(r,g,b,mid+1,maxim));
		else
			return mid;
	}
	return bin(r,g,b,minim,mid-1);
}

int main(){
	long long int ans,r,g,b,k,sum;
	cin>>r>>g>>b;
	sum=(r+g+b);
	k=sum/3;

	ans=bin(r,g,b,0,k);	
	cout<<ans<<endl;
	return 0;
}