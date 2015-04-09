#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;
std::vector<ll> dp(111111,0);
int main() {
	ll t,i;
	cin>>t;
	int val[5]={2,3,6,7,8};
	while(t--){
		fill(dp.begin(),dp.end(),0);
		ll n;
		cin>>n;
		dp[0]=1;
		for(ll k=0;k<5;k++){
			for (i = 0; i <=n ; ++i)
			{
				dp[i+val[k]]+=dp[i];
			}
		}	
		cout<<dp[n]<<endl;
	}
	return 0;
}