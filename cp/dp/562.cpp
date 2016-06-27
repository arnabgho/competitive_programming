#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;

bool DP[101][101*501];

int main() {
	int n;
	cin>>n;
	for (int i = 0; i < n; ++i)
	{
		memset(DP,0,sizeof(DP));
		int m;
		cin>>m;
		std::vector<int> v(m+1,0);
		for (int i = 1; i <=m ; ++i)
		{
			cin>>v[i];
		}
		DP[0][0]=1;
		for (int i = 1; i <=m ; ++i)
		{
			for (int j = 0; j <=101*501 ; ++j)
			{
				DP[i][j]|=DP[i-1][j];
				if(j>=v[i])
					DP[i][j]|=DP[i-1][j-v[i]];
			}
		}
		int best=1e9;
		int sum=accumulate(v.begin(),v.end(),0);
		for (int j = 0; j <=sum ; ++j)
		{
			if(DP[m][j])
				best=min(best,abs(sum-2*j));
		}
		cout<<best<<endl;
	}
	return 0;
}