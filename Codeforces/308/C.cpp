#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;
typedef long long ll;
// ctrl+H int -> ll
std::vector<ll> v;
ll getMax(ll w,ll m){
	ll k=1;
	ll ans=1;
	while(k<=m){
		v.push_back(k);
		k*=w;
		ans++;
	}
	v.push_back(k);
	return ans;
}

ll Pow(ll w,ll p){
	ll ans=1;
	for (int i = 0; i < p; ++i)
	{
		ans*=w;
	}
	return ans;
}

int main() {
	ll w,m;
	cin>>w>>m;
	ll n=getMax(w,m);
	n=v.size();
	bool pos=0;
	
	for(ll mask=0;mask<Pow(3,n) && !pos;mask++){
		ll temp=mask;
		ll val=0;
		for (ll i = 0; i <n ; ++i)
		{
			if(temp%3==1){
				val+=v[i];
			}
			else if(temp%3==2){
				val-=v[i];
			}
			temp/=3;
		}
		pos=(val==m);
	}
	if(pos)
		cout<<"YES\n";
	else
		cout<<"NO\n";
	return 0;
}