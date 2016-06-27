#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;
typedef long long ll;

std::vector<ll> v;
std::vector<ll> minim(11111);
std::vector<ll> maxim(11111);
std::vector<bool> val(11111);
int main() {
	ll T;
	cin>>T;
	for (ll cas = 1; cas <=T ; ++cas)
	{
		v.clear();
		ll E,R,N;
		ll res=0;
		cin>>E>>R>>N;
		for (ll i = 0; i < N; ++i){
			ll x;cin>>x;v.push_back(x);
		}
		fill(minim.begin(),minim.end(),0);
		fill(maxim.begin(), maxim.end(),E);
		fill(val.begin(), val.end(),1);
		for (ll i = 0; i < N; ++i)
		{
			ll maxpos=0;
			ll mx=0;
			for (ll j = 0; j < N; ++j)
			{
				if(!val[j]) continue;
				if(v[j]>mx){mx=v[j];maxpos=j;}
			}
			val[maxpos]=0;
			if(maxim[maxpos]>=minim[maxpos])
				res+=(maxim[maxpos]-minim[maxpos])*mx;
			for (ll j = maxpos+1; j <N ; ++j)
			{
				ll value=(j-maxpos)*R>E ? E:(j-maxpos)*R;
				maxim[j]=min(maxim[j],value);
			}
			for (ll j = maxpos-1; j >=0 ; --j)
			{
				ll value=(-j+maxpos)*R>E ? 0:E-(-j+maxpos)*R;
				minim[j]=max(minim[j],value);
			}
		}
		cout<<"Case #"<<cas<<": "<<res<<endl;
	}
	return 0;
}