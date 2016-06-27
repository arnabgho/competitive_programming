#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
#define fi first
#define se second
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
const ll mod=1000000007;
ll powmod(ll a,ll b) {ll res=1;a%=mod;for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
// head

ll DP[2100][2100];
ll DP2[2100][2100];

int main(){
	int n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	ll val_s=0;
	ll minbal=1e9;
	for (int i = 0; i < s.size(); ++i)
	{
		if(s[i]=='(')
			val_s++;
		else
			val_s--;
		minbal=min(minbal,val_s);		
	}
	if(n==m){
		if(val_s==0 && minbal>=0)
			cout<<1<<endl;
		else
			cout<<0<<endl;
		return 0;
	}
	memset(DP,0,sizeof(DP));
	DP[0][0]=1;
	for (int i = 0; i <= 2050; ++i)
	{
		for (int j = 0; j <=2050 ; ++j)
		{
			if(DP[i][j]!=0){
				DP[i+1][j+1]=(DP[i][j]+DP[i+1][j+1])%mod;
				if(j>0)
					DP[i+1][j-1]=(DP[i][j]+DP[i+1][j-1])%mod;
			}
		}
	}
	// cout<<"val_s "<<val_s<<endl;
	ll ans=0;
	for (int l1 = 0; l1 <= n-m ; ++l1)
	{
	 	int l2=n-m-l1;
	 	for (int val = 0; val <=l1 ; ++val)
	 	{
	 		if(val+minbal>=0)
	 			if(val_s+val<=n-m && val_s+val>=0)
	 				ans=(ans+(DP[l1][val]*DP[l2][val+val_s])%mod)%mod;	
	 	}
	}
	cout<<ans<<endl;
	return 0;	
}
