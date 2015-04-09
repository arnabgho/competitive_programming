#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;

typedef unsigned long long LL;
LL MOD=1e9+7ULL;

LL binSearch(LL min,LL max,LL toFind){
	LL k=(min+max)>>1ULL;
	if((k-k/(21ULL))==toFind)
		return k;
	else if((k-k/(21ULL))>toFind)
		return binSearch(min,k,toFind);
	else
		return binSearch(k,max,toFind);
}

int main() {
	LL t,n,s,k;
	cin>>t;
	while(t--){
		cin>>s;
		LL k=binSearch(0ULL,1e18*4ULL,s);
		LL n=k<<1ULL;
		cout<<n%MOD<<endl;
	}
	return 0;
}