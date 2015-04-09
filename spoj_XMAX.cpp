#include <stdio.h>
#include <algorithm>
#include <math.h>
#include <iostream>
#include <vector>

using namespace std;

typedef long long int LL;
std::vector<LL> v;

bool getBit(LL num,int i){
	return (((num) & (1LL<<i))!=0);
}

int main() {
	LL n,i,a,maxbits,ans,curpos,j,currel,temp;
	cin>>n;
	for(i=0;i<n;i++){
		cin>>a;
		v.push_back(a);
	}
	sort(v.rbegin(),v.rend());
	maxbits=ceil(log2(v[0]))+1;
	ans=0;
	curpos=0;
	// cout<<"maxbits :"<<maxbits<<endl;
	for(i=maxbits-1;i>=0;i--){
		bool found=false;
		for(j=curpos;j<n;j++){
			if(getBit(v[j],i)){
				swap(v[j],v[curpos]);found=true;break;
			}
		}
		if(!found) continue;
		for(j=0;j<n;j++){
			if(j!=curpos && getBit(v[j],i)){
				v[j]=v[j]^v[curpos];
			}
		}
		curpos++;
	}
	ans=0;
	for(i=0;i<n;i++){
		// cout<<"v[i] : "<<v[i]<<endl;
		// cout<<"ans^v[i]: "<<(ans^v[i])<<endl;
		temp=(ans^v[i]);
		ans=temp;
	}
	cout<<ans<<endl;
	return 0;
}