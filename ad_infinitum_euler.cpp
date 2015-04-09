#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;
typedef long long LL;
LL MOD,n,k;

LL getResult(){
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

int main() {
	LL t,A,M,res;
	cin>>t;
	while(t--){
		cin>>A>>M;
		if(A==1 || A==0){
			cout<<"YES"<<endl;	
			continue;
		}
		n=A;
		k=(M-1)/2LL;
		MOD=M;
		res=getResult();
		if(res==1)
			cout<<"YES\n";
		else
			cout<<"NO\n";
	}
	return 0;
}