#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;

typedef long long int LL;
LL MOD=1e9+7LL;
int main() {
	LL t,s,n,forward,backward,ans;
	cin>>t;
	while(t--){
		cin>>s;
		n=(21LL*s)/10LL;
		if(n%2==1)
			n++;
		forward=n;backward=n;
		bool found=0;
		while(!found){
			if(forward/(2LL)-forward/(42LL)==s){
				ans=forward;found=true;break;
			}
			if(backward/(2LL)-backward/(42LL)==s){
				ans=backward;found=true;break;
			}
			forward+=2;
			backward-=2;
		}
		cout<<ans%MOD<<endl;
	}
	return 0;
}