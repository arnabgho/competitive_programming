#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> pi;
const long double eps=1e-9;
map<pi,long double> DP;
int main() {
	ll t;
	cin>>t;
	for (ll cas = 1; cas <= t; ++cas)
	{
		long double b;
		int L,N;
		cin>>b>>L>>N;
		long double vol=b*750.0;
		long double ans=0;
		DP.clear();
		int cur=1;
		for(int i=1;i<=L+10;i++){
			for(int j=1;j<=cur;j++){
				DP[pi(i,j)]=0;
			}
			cur+=i+1;
		}

		cur=1;
		DP[pi(1,1)]=750.0*b;
		for(int i=1;i<=L+10;i++){
			for(int j=1;j<=cur;j++){
				if(DP[pi(i,j)]>=250){
					long double surplus=DP[pi(i,j)]-250;
					DP[pi(i,j)]=250;
					DP[pi(i+1,j)]+=surplus/3.0;
					DP[pi(i+1,j+i)]+=surplus/3.0;
					DP[pi(i+1,j+i+1)]+=surplus/3.0;
				}
			}
			cur+=i+1;
		}
		printf("Case #%lld: %.15Lf\n",cas,DP[pi(L,N)] );
	}
	return 0;
}