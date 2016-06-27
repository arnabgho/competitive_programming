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

int P,N,T;

ll recurse(int cur,int rem){
	if(cur>N && rem==0)
		return 1;
	if(cur>N && rem!=0)
		return 0;
	PII p=PII(cur,rem);
	if(DP.count(p))
		return DP[p];
	ll ans=0;
	for (int i = P; i <= rem-(N-cur)*P ; ++i)
	{
		ans+=recurse(cur+1,rem-i);
	}
	return DP[p]=ans;
}

int main(){
	int test;
	cin>>test;
	for (int cas = 1; cas <=test ; ++cas)
	{
		DP.clear();
		cin>>N>>T>>P;
		ll ans=recurse(1,T);
		cout<<ans<<endl;
	}
	return 0;		
}
