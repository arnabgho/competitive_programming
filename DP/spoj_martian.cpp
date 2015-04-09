#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;


int Y[600][600];
int B[600][600];
int sum[2][600][600];
int dp[600][600];
int n,m;

void solve(){

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			int temp1=sum[0][i][j];
			int temp2=sum[1][i][j];
			if(i>0)
				temp1+=dp[i-1][j];
			if(j>0)
			temp2+=dp[i][j-1];
			dp[i][j]=max(temp1,temp2);
		}
	}

}


int main() {
	cin>>n>>m;
	while(!(n==0 && m==0)){
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				cin>>Y[i][j];
				sum[0][i][j]=0;
				dp[i][j]=0;
			}
		}
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				cin>>B[i][j];
				sum[1][i][j]=0;
			}
		}

		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				if(j==0)
					sum[0][i][j]=Y[i][j];
				else
					sum[0][i][j]=sum[0][i][j-1]+Y[i][j];
			}
		}

		for (int j = 0; j < m; ++j)
		{
			for (int i = 0; i < n; ++i)
			{
				if(i==0)
					sum[1][i][j]=B[i][j];
				else
					sum[1][i][j]=sum[1][i-1][j]+B[i][j];
			}
		}
		solve();
		cout<<dp[n-1][m-1]<<endl;
		cin>>n>>m;
	}
	return 0;
}