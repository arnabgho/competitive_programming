#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;
typedef long long ll;
ll A,B,n;
ll l,t,m;
ll cumsum(ll n){
	return A*n+B*(n*(n-1))/2;
}
bool checkpos(ll r){
	ll h=A+(r-1)*B;
	ll sum=cumsum(r)-cumsum(l-1);
	return h<=t && sum<=m*t;
}

int main() {
	cin>>A>>B>>n;
	for (ll i = 0; i < n; ++i)
	{
		cin>>l>>t>>m;
		ll mn=A+(l-1)*B;
		ll mx=l;
		if(mn>t){
			cout<<"-1\n";continue;
		}
		ll lo=l;
		ll hi=1e9;
		while(lo < hi){
			ll x=lo+(hi-lo)/2;
			if(checkpos(x)){
				mx=max(mx,x);
				lo=x+1;
			}
			else{
				hi=x;
			}
		}
		cout<<mx<<endl;	
	}
	return 0;
}