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

std::vector<PII> M,F;

bool can_come(int day,int fday,int lday){
	return fday<=day && day<=lday;
}

int main(){
	int n;
	cin>>n;
	char c;
	int a,b;
	for (int i = 0; i < n; ++i)
	{
		cin>>c>>a>>b;
		if(c=='M')
			M.push_back(PII(a,b));
		else
			F.push_back(PII(a,b));
	}

	int maxim=0;
	for (int d = 1; d <=366 ; ++d)
	{
		int males=0;
		int females=0;
		for (int i = 0; i < M.size(); ++i)
			if(can_come(d,M[i].fi,M[i].se))
				males++;
		for (int i = 0; i < F.size(); ++i)
			if(can_come(d,F[i].fi,F[i].se))
				females++;
		int num_this_day=2*min(males,females);	
		maxim=max(maxim,num_this_day);	
	}
	cout<<maxim<<endl;
	return 0;	
}
