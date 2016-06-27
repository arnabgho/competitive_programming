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

map<PII,ll> DP;

ll recurse(int n,int k,int m){
	if(k==0 && n>=0)
		return 1;
	if(k==0 && n<0)
		return 0;
	if(k==1 && n>=0)
		return min(n,m);
	PII p=PII(n,k);
	if(DP.count(p))
		return DP[p];

	ll ans=0;
	for (int l = 2; l <=n-( 2*(k-1)-1 ) ; ++l)
	{
		ans+=recurse(n-l,k-1,m)*min(l-1,m);
	}
	cout<<"n "<<n <<" k "<<k<<" ans "<<ans<<endl;
	return DP[p]=ans;
}


int main(){
	int n,k,m;
	while(scanf("%d %d %d",&n,&k,&m)!=EOF){
		DP.clear();
		ll ans=recurse(n,k,m);
		printf("%lld\n",ans );
	}
	return 0;	
}
