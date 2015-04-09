#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;

typedef long long ll;
map<ll,ll> memo;
std::vector<int> a;
multiset<ll> num;
int main() {
	ll n,k;
	cin>>n>>k;
	a.push_back(0);
	for (int i = 0; i < n; ++i) {ll x;cin>>x;a.push_back(x);}

	ll ans=0;
	ll right=0;
	// memo[a[0]]=1;
	ll f=0;
	for (int left= 1; left <= n; ++left){	
		if(left){
			memo[a[left-1]]--;
			if(memo[a[left-1]]==k-1)
				f--;
		}

		while(!f && right<n){
			right++;
			memo[a[right]]++;
			if(memo[a[right]]>=k) ++f;
		}
		if(f)
			ans+=n-right+1;
	}	
	cout<<ans<<endl;
	return 0;
}