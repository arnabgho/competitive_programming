#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;

typedef long long ll;
std::vector<ll> v(111111,0);
typedef pair<ll,ll> pl;
std::vector<pl> A,R;
// -1 left 0 ! 1 right

int main() {
	ll n;
	cin>>n;
	R.push_back(pl(0,-1e12));
	for (ll i = 0; i < n; ++i)
	{
		ll x,h;
		cin>>x>>h;
		R.push_back(pl(h,x));
		A.push_back(pl(h,i+1));
	}
	R.push_back(pl(0,1e12));
	sort(A.rbegin(),A.rend());
	ll ans=0;
	for (ll i = 0; i < A.size(); ++i)
	{
		ll pos=A[i].second;
		ll x=R[pos].second;
		ll h=A[i].first;
		ll dleft,dright;
		if(v[pos+1]==0 || v[pos+1]==1){
			dright=R[pos+1].second-x-1;
		}
		if(v[pos+1]==-1){
			dright=R[pos+1].second-x-1-R[pos+1].first;
		}

		if(v[pos-1]==0 || v[pos-1]==-1){
			dleft=-R[pos-1].second+x-1;
		}
		if(v[pos-1]==1){
			dleft=-R[pos-1].second+x-1-R[pos-1].first;
		}

		// cout<<"pos "<<pos<<" height "<<A[i].first<<endl;
		// cout<<"dright "<<dright<<" "<<" dleft "<<dleft<<endl;
		if(dright<=0 && dleft<=0) continue;
		else if(dleft>dright && dleft>=h){
			v[i]=-1;
			ans++;
		}
		else if( dright>=h) {
			v[i]=1;
			ans++;
		}
	}
	cout<<ans<<endl;
	return 0;
}