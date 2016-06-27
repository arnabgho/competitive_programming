#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;
typedef long long ll;
struct H{
	int a,b,c;
};
bool operator <(const H& x, const H& y) {
    return std::tie(x.a, x.b, x.c) < std::tie(y.a, y.b, y.c);
}
map<H,ll> dp;
// int dp[501][501][501];
int a[600];
int main() {
	int n, m, b, mod;
	cin>>n>>m>>b>>mod;
	
	for (int i = 1; i <=n ; ++i)
	{
		cin>>a[i];
	}
	H h={0,0,0};
	dp[h]=1;
	for (int i = 1; i <=n ; ++i)
	{
		for (int j = 0; j <=m ; ++j)
		{
			for (int k = 0; k <=b ; ++k)
			{
				for (int p = j; p >=0  ; --p)
				{
					if(k-a[i]*(j-p)<0) break;
					// cout<<"p "<<p<<endl;
					h={i-1,p,k-a[i]*(j-p)};
					H ht={i,j,k};
					dp[ht]+=dp[h];
				}
			}
		}
	}
	int res=0;
	for (int i = 0; i <=b; ++i)
	{
		H ht={n,m,i};
		res=(res+dp[ht])%mod;
	}
	cout<<res<<endl;
	return 0;
}	