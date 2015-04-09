#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;
typedef long long LL;
LL MOD=1e7+7LL;
LL arr[50][50];
std::vector<LL> colsums;
int main() {	
	LL m,n,i,j;
	cin>>n>>m;
	for (i = 0; i < n; ++i)
	{
		for (j = 0; j < m; ++j)
		{
			cin>>arr[i][j];
		}
	}
	for ( i = 0; i < m; ++i)
	{
		LL sum=0;
		for (j = 0; j < n; ++j)
		{
			sum+=arr[j][i];
		}
		colsums.push_back(sum);
	}
	LL ans=1LL;
	for (LL i = 0; i < m; ++i)
	{
		ans=(ans*colsums[i])%MOD;
	}
	cout<<ans<<endl;
	return 0;	
}