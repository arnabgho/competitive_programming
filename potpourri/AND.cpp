#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;
typedef long long int LL;
int main() {
	LL t,A,B;
	cin>>t;
	while(t--){
		std::vector<LL> bitsA(32,0);
		std::vector<LL> bitsB(32,0);
		std::vector<LL> bitsAns(32,0);
		cin>>A>>B;
		for (LL i = 0; i <= 32; ++i)
		{
			if((A&(1LL<<i))!=0)
				bitsA[i]=1;
			if((B&(1LL<<i))!=0)
				bitsB[i]=1;
		}
		for (LL i = 32; i >=0 ; i--)
		{
			if(bitsA[i]!=bitsB[i])
				break;
			else
				bitsAns[i]=bitsA[i];
		}
		LL ans=0;
		for (LL i = 0; i <= 32; ++i)
		{
			ans+=(1LL<<i)*bitsAns[i];
		}
		cout<<ans<<endl;
	}
	return 0;
}