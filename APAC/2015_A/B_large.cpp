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
std::vector<long double> v;
int main(){
	int test;
	cin>>test;
	for (int cas= 1; cas <=test ; ++cas)
	{
		int n,m;
		cin>>n>>m;
		v.clear();
		for (int i = 0; i < n; ++i)
		{
			long double x;cin>>x;v.push_back(x);
		}
		printf("Case #%d:\n",cas );
		for (int i = 0; i <m ; ++i)
		{
			int l,r;
			cin>>l>>r;
			long double res=0;
			long double d=r-l+1;
			for (int j = l; j <=r ; ++j)
			{
				res+=log(v[j]);
				// cout<<"v[i] "<<v[i]<<endl;
				// cout<<"log "<<log(v[j])<<endl;
			}
			res=res/d;
			long double ans=exp(res);
			printf("%.15LF\n",ans );
		}
		
	}
	return 0;	
}
