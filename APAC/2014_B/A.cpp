#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;
typedef long long ll;
typedef pair<ll,ll> pi;
const double eps=1e-9;
ll DP[200][200][200];

const ll mod=1000000007;

long modPow(long a, long x, long p) {
    //calculates a^x mod p in logarithmic time.
    long res = 1;
    while(x > 0) {
        if( x % 2 != 0) {
            res = (res * a) % p;
        }
        a = (a * a) % p;
        x /= 2;
    }
    return res;
}

long modInverse(long a, long p) {
    //calculates the modular multiplicative of a mod m.
    //(assuming p is prime).
    return modPow(a, p-2, p);
}

void init(){
	DP[1][1][1]=1;
	for (int i = 1; i <=110 ; ++i)
	{
		for (int j = i; j <=110 ; ++j)
		{
			for (int k = 1; k <=j-i+1 ; ++k)
			{
				// DP[i][j]=((DP[i][j-1]*j*modInverse(2,mod) )%mod+ ( DP[i-1][j-1]*j)%mod)%mod;
				if(k==1){
					for (int l = 1; l <=j-i+1 ; ++l)
					{
						DP[i][j][k]=(DP[i][j][k]+DP[i-1][j-1][l]*j)%mod;
					}
				}
				else if(k==0){
					DP[i][j][k]=DP[i-1][j][k];
				}
				else if(k>1){
					DP[i][j][k]=(((DP[i][j-1][k-1]*j)%mod)*modInverse(k,mod))%mod;
				}
			}
		}
	}
}

int main() {
	ll t;
	init();
	cin>>t;
	for (ll cas = 1; cas <= t; ++cas)
	{
		ll m,n;
		cin>>m>>n;
		ll ans=0;
		for (int k = 1; k <=n-m+1 ; ++k)
		{
			ans=(ans+DP[m][n][k])%mod;
		}
		printf("Case #%lld: %lld\n",cas,ans );
	}
	return 0;
}
