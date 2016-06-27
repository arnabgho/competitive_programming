#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;
typedef long long ll;
std::vector<std::vector<ll> > v(200);
ll wins[200];
int main() {
	ll n,m;
	cin>>n>>m;
	for(int i=0;i<m;i++){
		for (int j = 0; j < n; ++j)
		{
			ll x;cin>>x;
			v[i].push_back(x);

		}
	}
	for (int i = 0; i < m; ++i)
	{
		ll max=-1;
		ll winner=-1;
		for (int j = 0; j <n ; ++j)
		{
			if(v[i][j]>max){
				max=v[i][j];
				winner=j;
			}
		}
		wins[winner]++;
	}
	ll max=-1;
	ll winner=-1;
	for (int i = 0; i < n; ++i)
	{
		if(wins[i]>max){
			max=wins[i];
			winner=i+1;
		}
	}
	cout<<winner<<endl;
	return 0;
		
}