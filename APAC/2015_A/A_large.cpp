#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (long long int i=a;i<n;i++)
#define per(i,a,n) for (long long int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define SZ(x) ((long long int)(x).size())
#define fi first
#define se second
typedef vector<long long int> VI;
typedef long long ll;
typedef pair<long long int,long long int> PII;
const ll mod=1000000007;
ll powmod(ll a,ll b) {ll res=1;a%=mod;for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
// head


long long int getValue(long long int K){
	if(K==1 || K==2) return 0;
	long long int n=0;
	long long int c=0;
	while(1){
		c++;
		if(2*n+1>=K) break;
		n=2*n+1;
	}
	// cout<<"n "<<n<<" K "<<K<<endl;
	// cout<<"-------\n";
	if(K-n==1)
		return 0;
	else{
		return (1+getValue(2*n+1-K+1))%2;
	}
	// return 1;
}

int main(){
	long long int test;
	cin>>test;
	for (long long int cas = 1; cas <=test ; ++cas)
	{
		long long int K;
		cin>>K;
		long long int ans=getValue(K);
		printf("Case #%lld: %lld\n",cas,ans );
	}
	return 0;	
}
