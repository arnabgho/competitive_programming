#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;


typedef long long ll;

ll gcd(ll a,ll b){
	if(b==0)
		return a;
	return gcd(b,a%b);
}

int main() {
	ll a,b;
	cin>>a>>b;
	ll n=0;
	ll g=gcd(a,b);
	// cout<<"g "<<g<<endl;
	while(a!=b){
		n++;
		ll x=b;
		ll y=a-b;
		a=max(x,y);
		b=min(x,y);
		// cout<<"x "<<x<<" y "<<y<<endl;
		if(b==g)
		{
			// cout<<"a "<<a<<" b "<<b<<endl;
			n+=a/b;
			break;
		}

	}
	cout<<n<<endl;
	return 0;
}