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
	LL n,i,a,maxbits,ans,curpos,j,currel,temp,t;
	cin>>n;
	for(i=0;i<n;i++){
		cin>>a;
		v.push_back(a);
	}
	sort(v.rbegin(),v.rend());
	ans=0;
	curpos=0;
	LL sig=1;
	while(sig<=v[0])
		sig=sig<<1;
	sig=sig>>1;
	// cout<<"maxbits :"<<maxbits<<endl;
		// cout<<"sig : "<<sig<<endl;		
	for(t=0;sig>=1;sig=sig>>1){
			i=t;
			while(i<n && ((v[i]&sig)==0)) i++;

			if(i>=n) continue;

			swap(v[i],v[t]);
			for(i=0;i<n;i++){
				if(i!=t && ((v[i]&sig)!=0)){
					v[i]=v[i]^v[t];
				}
			}
			t++;	
	}
	ans=0;
	for(i=0;i<n;i++)
		ans=ans^v[i];
	cout<<ans<<endl;
	return 0;
}