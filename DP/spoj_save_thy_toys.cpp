#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <cstring>
#include <stdio.h>
using namespace std;

const int MAXM=111111;
std::vector<long long int> v(MAXM);
const long long int inf=1e7;
long long int dp1[MAXM],dp2[MAXM],dp3[MAXM];
long long int sum[MAXM];
int main() {
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		for (int i = 0; i < n; ++i)
		{
			scanf("%lld",&v[i]);
		}
		memset(dp1,-inf,sizeof(dp1));
		memset(dp2,-inf,sizeof(dp2));
		memset(dp3,-inf,sizeof(dp3));
		sum[0]=v[0];
		for (int i = 1; i <n ; ++i)
		{
			sum[i]=sum[i-1]+v[i];
		}
		if(n<4){
			cout<<sum[n-1]<<endl;
			continue;
		}
		dp1[0]=sum[0];
		dp2[1]=sum[1];
		dp3[2]=sum[2];
		dp1[2]=v[0]+v[2];
		long long int ans=0;
		for (int i = 3; i < n; ++i)
		{
			long long int k=max(max(dp1[i-2],dp2[i-3]),dp3[i-4]);
			dp1[i]=k+v[i];
			dp2[i+1]=k+v[i]+v[i+1];
			dp3[i+2]=k+v[i]+v[i+1];
		}
		for (int i = 0; i <n ; ++i)
		{
			ans=max(max(dp1[i],dp2[i]),max(dp3[i],ans));
		}
		printf("%lld\n",ans );
	}
	return 0;
}