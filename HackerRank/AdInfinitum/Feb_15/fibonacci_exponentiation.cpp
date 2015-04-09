#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;
typedef long long int ll;
typedef std::vector<ll> vi;



const ll mod=1e9+7;

ll nfib(ll A,ll B,ll n){
	std::vector<vi> X(2,vi(2,1));
	std::vector<vi> Y(2,vi(2,1));

	Y[1][1]=0;
	X[1][0]=0;
	X[0][1]=0;
	while(n>0){
		if(n%2==1){
			std::vector<vi> W(2,vi(2,0));
			for (int i = 0; i < 2; ++i)
			{
				for (int j = 0; j < 2; ++j)
				{
					for (int k = 0; k < 2; ++k)
					{
						W[i][j]+=X[i][k]*Y[k][j];
						W[i][j]%=mod;
					}
				}
			}
			X=W;
		}	
		std::vector<vi> Z(2,vi(2,0));
		for (int i = 0; i < 2; ++i)
		{
			for (int j = 0; j < 2; ++j)
			{
				for (int k = 0; k < 2; ++k)
				{
					Z[i][j]+=Y[i][k]*Y[k][j];
					Z[i][j]%=mod;
				}
			}
		}
		Y=Z;
		n/=2;
	}

	ll ans=B*X[1][0]+A*X[1][1];
	return ans%mod;
}

int main() {

	ll A,B,n;
	int t;
	cin>>t;
	while(t--){
		cin>>A>>B>>n;
		ll ans=nfib(A,B,n);
		cout<<ans<<endl;
	}	
	return 0;
}