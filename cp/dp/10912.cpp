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

typedef pair<PII,int> PIII;
map<PIII,ll> DP;

ll recurse(int prev,int L,int S){
	if(L==0 && S==0)
		return 1;
	else if(L==0 && S!=0)
		return 0;
	PIII p=PIII(PII(prev,L),S);
	if(DP.count(p))
		return DP[p];
	ll ans=0;
	for (int i = prev+1; i <=26 ; ++i)
	{
		ans+=recurse(i,L-1,S-i);
	}
	return DP[p]=ans;
}

int main(){
	int L,S,cas=1;
	cin>>L>>S;
	while(L+S>0){
		DP.clear();
		ll ans;
		if(L>26)
			ans=0;
		else
			ans=recurse(0,L,S);
		printf("Case %d: %lld\n",cas++,ans );
		cin>>L>>S;
	}
	return 0;	
}
