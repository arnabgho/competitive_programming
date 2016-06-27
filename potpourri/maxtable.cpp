#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;
int DP[100][100];
int main() {
	int n;
	cin>>n;
	for (int i = 1; i <=n ; ++i)
	{
		DP[i][1]=1;
		DP[1][i]=1;
	}
	int ans=1;
	for (int i = 2; i <=n ; ++i)
	{
		for (int j = 2; j <=n ; ++j)
		{
			DP[i][j]=DP[i-1][j]+DP[i][j-1];
			ans=max(DP[i][j],ans);
		}
	}
	cout<<ans<<endl;
	return 0;
}