#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;
typedef long long ll;
// struct H{
// 	int a,b,c;
// };
// bool operator <(const H& x, const H& y) {
//     return std::tie(x.a, x.b, x.c) < std::tie(y.a, y.b, y.c);
// }
// map<H,int> dp;
int dp[2][501][501];
int a[600];

int modulo(int n,int mod){
	if(n>mod) return n-mod;
	return n;
}

int main() {
	int n, m, b, mod;
	cin>>n>>m>>b>>mod;
	
	for (int i = 1; i <=n ; ++i)
	{
		cin>>a[i];
	}
	// H h={0,0,0};
	dp[0][0][0]=1;
	int cur=0,prev=0;
	for (int i = 1; i <=n ; ++i)
	{
		cur=i%2;
		prev=(i+1)%2;
		for (int j = 0; j <=m ; ++j)
		{
			for (int k = 0; k <=b ; ++k)
			{
				dp[cur][j][k]=dp[prev][j][k];
				if(j>0 && k-a[i]>=0)
					dp[cur][j][k]= modulo(dp[cur][j][k]+ dp[cur][j-1][k-a[i]],mod);
			}
		}
	}
	int res=0;
	for (int i = 0; i <=b; ++i)
	{
		// H ht={n,m,i};
		res=modulo(res+dp[cur][m][i],mod);
	}
	cout<<res%mod<<endl;
	return 0;
}	