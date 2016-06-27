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

ll power(ll a,ll b){
	ll res=1;
	for(ll i=1;i<=b;i++){
		res*=a;
	}
	return res;
}

int main(){
	ll l,r,k;
	double n;	
	cin>>l>>r>>k;
	n=log(1.0*l)/log(1.0*k);
	bool f=0;
	for (ll i = n; i < 1e9; ++i)
	{
		ll pw=power(k,i);
		if(pw>r) break;
		if(l<=pw && pw<=r){
			f=1;
			cout<<pw<<" ";
		}
	}
	if(!f)
		cout<<"-1";
	cout<<endl;
	return 0;	
}
