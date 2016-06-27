#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;

typedef long long ll;
typedef std::vector<ll> vi;
std::vector<vi> v(222222);
multiset<ll> m;
int main() {
	ll n;
	cin>>n;
	for (ll i = 1; i <= n; ++i)
	{
		ll x;
		cin>>x;
		v[x].push_back(i);
		m.insert(x);
	}
	bool pos=1;
	ll khali=0;
	std::vector<ll> res;
	cout<<"m.size() "<<m.size()<<endl;
	while(pos && m.size()>0){
		ll mx=*m.rbegin();
		cout<<"mx "<<mx<<endl;
		cout<<"khali "<<khali<<endl;
		cout<<"--------\n";
		if(khali>=mx && khali%3!=mx%3){
			pos=0;break;
		}

		if(khali>=mx && khali%3==mx%3){
			khali=mx+1;
			m.erase(m.find(mx));
			ll p=v[mx][0];
			v[mx].erase(v[mx].begin());
			cout<<"Inseting "<<p<<endl;
			res.push_back(p);
		}
		else if(khali<mx){
			bool f=1;
			for(int i=khali;i<=mx;i++)
				if(m.find(i)==m.end()) f=0;
			if(!f) {pos=0;break;}
			else{
				for(int i=khali;i<=mx;i++){
					ll p=v[i][0];
					v[i].erase(v[i].begin());
					m.erase(m.find(i));
					cout<<"Inseting 1 "<<p<<endl;
					res.push_back(p);
					cout<<"m.size() "<<m.size()<<endl;
					khali=mx+1;
				}
			}
		}
	}
	if(pos){
		cout<<"Possible\n";
		for (int i = 0; i < res.size(); ++i)
		{
			cout<<res[i]<<" ";
		}
		cout<<endl;
	}
	else
		cout<<"Impossible\n";
	return 0;
}