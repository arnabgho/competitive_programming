#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;

typedef long long ll;

bool getBit(ll x,ll i){
	return (x>>i & 1 );
}

ll count(ll i,bool lessA,bool lessB,bool lessC,ll A,ll B,ll C){
	if(i==-1)
		return lessA && lessB && lessC;
	bool maxA= lessA | getBit(A,i)==1;
	bool maxB= lessB | getBit(B,i)==1;
	bool maxC= lessC | getBit(C,i)==1;
	ll res=count(i-1,maxA,maxB,maxC,A,B,C);
	if(maxA){
		res+=count(i-1,lessA,maxB,maxC,A,B,C);
	}
	if(maxB){
		res+=count(i-1,maxA,lessB,maxC,A,B,C);
	}
	if(maxC){
		res+=count(i-1,lessA,lessB,lessC,A,B,C);
	}
	return res;
}

int main() {
	int T;
	cin>>T;
	for (int cas = 1; cas <=T ; ++cas)
	{
		ll A,B,K;
		cin>>A>>B>>K;
		ll res=count(31,0,0,0,A,B,K);
		cout<<"Case #"<<cas<<": "<<res<<endl;
	}
	return 0;
}