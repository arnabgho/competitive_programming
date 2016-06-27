#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;
typedef long long ll;

std::vector<ll> M;
ll B,N;

ll count(ll Time){
	ll ans=0;
	for (int i = 0; i < B; ++i)
	{
		if(Time%M[i]==0)
			ans+=Time/M[i];
		else
			ans+=Time/M[i]+1;
	}
	return ans;
}

int main() {
	ll T;
	cin>>T;
	for(ll cas=1;cas<=T;cas++){
		cin>>B>>N;
		M.clear();
		for (int i = 0; i < B; ++i)
		{
			ll x;
			cin>>x;
			M.push_back(x);
		}
		ll lo=1;
		ll hi=1e18;
		ll Ti=1;
		while(lo<hi){
			ll mid=lo+(hi-lo)/2LL;
			ll left=count(mid-1);
			ll right=count(mid);
			if(left<N && N<=right){
				Ti=mid;break;
			}
			if(right<N){
				lo=mid+1;
			}
			if(left>=N){
				hi=mid;
			}
		}
		Ti--;
		ll numServed=count(Ti);
		ll position=N-numServed;
		// cout<<"Time : "<<Ti<<endl;
		ll res=0;
		for (ll i = 0; i < B; ++i)
		{
			if(Ti%M[i]==0){
				position--;
				if(position==0){
					res=i+1;break;
				}
			}

		}
		cout<<"Case #"<<cas<<": "<<res<<endl;
	}
	return 0;
}