#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;
typedef long long int ll;
typedef std::vector<ll> vi;

const ll mod=1e9+7;

ll gcd(ll a,ll b){
	if(a==0)
		return b;
	return gcd(b%a,a);
}

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


ll inverse(ll a,ll n){
	ll t=0;
	ll r=n;
	ll newt=1;
	ll newr=a;
	while(newr!=0){
		ll q=r/newr;
		ll t1,t2;
		t1=t;
		t2=newt;
		t=t2;
		newt=t1-q*t2;
		t1=r;
		t2=newr;
		r=t2;
		newr=t1-q*t2;	
	}
	if(t<0) t+=n;
	return t;
}

stack<ll> fibs;

ll lcm(){
	int n=fibs.size();
	if(n==1)
		return fibs.top();
	while(fibs.size()>1){
		ll x1=fibs.top();
		fibs.pop();
		ll x2=fibs.top();
		fibs.pop();
		ll num=(x1*x2)%mod;
		ll g=gcd(x1,x2);
		ll gi=inverse(g,mod);
		num*=gi;
		num%=mod;
		fibs.push(num);
	}
	ll ans=fibs.top();
	fibs.pop();
	if(ans<0) ans+=mod;
	return ans;
}

int main() {
	int N;
	cin>>N;
	for (int i = 0; i < N; ++i)
	{
		ll a;
		cin>>a;
		fibs.push(nfib(0,1,a));
	}
	// cout<<"Hi \n";
	ll ans=lcm();
	cout<<ans<<endl;
	return 0;
}