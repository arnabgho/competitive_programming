#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;
typedef long long ll;
std::vector<ll> v(1000009,1);
std::vector<ll> N(1000009,1);
std::vector<bool> primes(1000009,1);

std::vector<ll> P;
void sieve(ll n){
	for (ll i = 2; i <n; ++i)
	{
		if(primes[i]){
			P.push_back(i);
			for (ll k = i*i; k <n ; k=k+i)
			{
				primes[k]=0;
			}
		}
	}
}
void init(){
	sieve(1000009);
	v[0]=0;
	v[1]=1;
	v[2]=2;
	ll i=3;
	while(i<1e6+9){
		if(primes[i]){
			v[i]=2;
		}
		else{
			for (ll j=0;j<P.size();j++)
			{
				ll x=P[j];
				if(i%x==0){
					if(i==2843)
						cout<<"x "<<x<<" v[x] "<<v[x]<<"v[x/i] "<<v[x/i]<<endl;

					v[i]=(v[x]*v[i/x]-1);
					break;
				}
			}
		}
		i++;
		// cout<<"i "<<i<<endl;
	}
	cout<<"v[54017] "<<v[54017]<<endl;
	// cout<<"Hey\n";
	N[0]=1;
	for(int i=1;i<1000009;i++){
		ll x=N[i-1];
		// cout<<"x "<<x<<" v[x] "<<v[x]<<endl;
		N[i]=x+v[x];
	}
}

int main() {
	ll t;
	cin>>t;
	init();
	for(int i=0;i<10;i++)
		cout<<v[i]<<" ";
	cout<<endl;
	for(int i=0;i<10;i++)
		cout<<N[i]<<" ";
	cout<<endl;
	for(ll cas=1;cas<=t;cas++){
		ll a,b;
		cin>>a>>b;
		std::vector<ll>::iterator it_left,it_right;
		it_left=lower_bound(v.begin(), v.end(),a);
		it_right=upper_bound(v.begin(), v.end(),b);
		ll num=it_right-it_left;
		printf("Case %lld: %lld\n",cas,num );
	}
	return 0;
}