#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;
typedef long long ll;
typedef pair<ll,ll> pi;

ll nChoosek( ll n, ll k )
{
    if (k > n) return 0;
    if (k * 2 > n) k = n-k;
    if (k == 0) return 1;

    ll result = n;
    for( int i = 2; i <= k; ++i ) {
        result *= (n-i+1);
        result /= i;
    }
    return result;
}

ll mCn(ll m,ll n,ll p){
	// cout<<"m "<<m<<" n "<<n<<endl; 
	if(m<n)
		return 0;
	if( n==0)
		return 1;
	if(n==1)
		return m%p;
	if(m<p && n<p)
		return nChoosek(m,n)%p;
	std::vector<ll> vm,vn;
	ll tm,tn;
	tm=m;
	tn=n;
	while(tm>0){
		vm.push_back(tm%p);
		tm/=p;
	}
	while(tn>0){
		vn.push_back(tn%p);
		tn/=p;
	}
	ll k=vm.size();
	ll k_n=vn.size();
	for (ll i = 0; i < k-k_n; ++i)
	{
		vn.push_back(0);
	}
	ll ans=1;
	for (ll i = 0; i <k ; ++i)
	{
		ans=ans*mCn(vm[i],vn[i],p);/* code */
		ans=ans%p;
	}
	return ans;
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

ll crt(std::vector<pi> v){
						//first -> ai second ->ni
	ll N=1;
	for (int i = 0; i < v.size(); ++i)
	{
		N*=v[i].second;/* code */
	}
	ll x=0;
	for (int i = 0; i < v.size(); ++i)
	{
		ll inv=inverse(N/v[i].second,v[i].second);
		x+=(v[i].first*N*inv)/v[i].second;
	}
	return x%N;
}

ll primes[15]={2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43 ,47}; //15

int main() {
	int t;
	cin>>t;
	while(t--){
		ll N,R,M;
		cin>>N>>R>>M;
		std::vector<pi> v;
		for (int i = 0; i < 15; ++i)
		{
			// cout<<"primes "<<primes[i]<<endl;
			// cout<<"M "<<M<<endl;
			// cout<<"M\%primes[i] "<<M%primes[i]<<endl;
			if(M%primes[i]==0){
				ll a=mCn(N,R,primes[i]);
				// cout<<"a "<<a<<endl;
				v.push_back(make_pair(a,primes[i]));
			}
		}
		// cout<<"Hello\n";
		ll ans=crt(v);
		cout<<ans<<endl;
	}
	return 0;
}