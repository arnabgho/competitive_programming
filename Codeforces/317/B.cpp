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

std::vector<ll> v;
ll A[1000000];
ll B[1000000];
int main(){
	int n,k;
	cin>>n>>k;
	memset(A,0,sizeof(A));
	memset(B,0,sizeof(B));
	for (int i = 0; i <n ; ++i)
	{
		ll x;cin>>x;v.push_back(x);	
	}
	sort(v.begin(), v.end());
	int pos=0;
	for (int i = 0; i <n ; ++i)
	{
		if(A[i]) continue;
		for (int j = 0; i+j <n ;j+=k )
		{
			A[i+j]=v[pos++];
		}
	}
	sort(v.rbegin(),v.rend());
	pos=0;
	for (int i = 0; i <n ; ++i)
	{
		if(B[i]) continue;
		for (int j = 0; i+j <n ;j+=k )
		{
			B[i+j]=v[pos++];
		}
	}
	ll ans_A=0;
	ll ans_B=0;
	for (int i = 0; i <n-k ; ++i)
	{
		ans_A+=abs(A[i]-A[i+k]);
		ans_B+=abs(B[i]-B[i+k]);
	}
	ll ans=min(ans_A,ans_B);

	

	// cout<<"\nA-\n";
	// for(int i=0;i<n;i++) cout<<A[i]<<" ";

	// cout<<"\nB-\n";
	// for(int i=0;i<n;i++) cout<<B[i]<<" ";
	// cout<<endl;
	cout<<ans<<endl;
	return 0;	
}
