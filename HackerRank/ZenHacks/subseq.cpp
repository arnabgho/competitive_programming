#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;
typedef long long ll;
const ll mod=1e9+7;
typedef std::vector<ll> vi;
vi a;
ll DP[111][2222][111];
int main() {
	ll m,r,s;
	cin>>m>>r>>s;
	if(r%2!=s%2){
		cout<<"0\n";
		return 0;
	}
	ll x=(r+s)/2;
	ll y=(r-s)/2;	
	// cout<<"x "<<x<<" y "<<y<<endl;
	for (ll i = 0; i < m; ++i)
	{
		ll x;
		cin>>x;
		a.push_back(x);
	}
	// DP[0][0][0]=0;
	for (ll i = 0; i <=m; ++i)
	{
		DP[i][0][0]=1;
	}
	for (ll i = 1; i <= m; ++i)
	{
		for (ll k = 0; k <=i ; ++k)
		{
			for (ll j = 0; j <=4000 ; ++j)
			{
				DP[i][j][k]=DP[i-1][j][k];
				if(j>=a[i-1])
					DP[i][j][k]=(DP[i][j][k]+DP[i-1][j-a[i-1]][k-1])%mod;
			}
		}
	}
	ll ans=0;
		for (ll k = 0; k <=m ; ++k)
		{
				ans=(ans+DP[m][x][k]+DP[m][y][k])%mod;
		}
	cout<<ans<<endl;			
	return 0;
}