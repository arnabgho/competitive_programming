#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;
typedef long long LL;
LL MOD=1e9+7;

LL getResult(LL n,LL k){
	LL val=n,res=1LL;
	while(k>0){
		if(k%2==1){
			res=(res*val)%MOD;
		}
		val=(val*val)%MOD;
		k/=2;
	}	
	// cout<<"res "<<res<<endl;
	return res%MOD;
}

std::vector<LL> A;
std::vector<LL> B;
std::vector<LL> P;
int main() {	
	LL 	n,i,p,a,b,res=1LL;
	cin>>n;
	for (int i = 0; i < n; ++i)
	{
		cin>>p>>b>>a;
		P.push_back(p);
		A.push_back(a);
		B.push_back(b);
	}
	for (int i = 0; i <n ; ++i)
	{
		if(A[i]==B[i]){
			res=(res*getResult(P[i],A[i]))%MOD;
		}
		else{
			LL temp=(getResult(P[i],A[i])+getResult(P[i],B[i]))%MOD;
			res=res*(temp)%MOD;
		}
	}
	cout<<res<<endl;
	return 0;
}