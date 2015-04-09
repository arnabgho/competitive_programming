#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;
typedef long long ll;
typedef pair<ll,ll> pi;
map<pi,ll> DP;
std::map<pi, bool> v;
const ll inf=1e9;
ll recurse(ll n,ll m){
	pi p=make_pair(n,m);
	if(v[p])
		return inf;
	v[p]=1;
	 // cout<<"n "<<n<<" m "<<m<<endl;
	if(n==m)
		return 0;
	else if(m<n)
		return n-m;
	
	if(DP.find(p)!=DP.end())
		return DP[p];
	ll minim=0;
	// if(n>1){
	// 	pi l=make_pair(n-1,m);
	// 	if(DP.find(l)!=DP.end())
	// 		minim=DP[l];
	// 	else
	// 		minim=recurse(n-1,m);
	// }
	// pi r=make_pair(2*n,m);
	// if(DP.find(r)!=DP.end())
	// 	minim=min(minim,DP[r]);
	// else
	// 	minim=min(minim,recurse(2*n,m));
	if(n>1)
		minim=min(recurse(n-1,m),recurse(2*n,m));
	else
		minim=recurse(2*n,m);
	DP[p]=minim+1;
	// cout<<"p "<<p.first<<" "<<p.second<<" Dp "<<DP[p]<<endl;
	return DP[p];
}

int main() {
	ll n,m;
	cin>>n>>m;
	// if(n==m)
	// 	cout<<"0\n";
	// else if(m<n)
	// 	cout<<n-m<<endl;
	// else{
	// 	ll ans=0;
	// 	while(2*n<=m){
	// 		n*=2;
	// 		ans++;
	// 	}
	// 	//cout<<"n "<<n<<endl;
	// 	if(n==m){
	// 		cout<<ans<<endl;
	// 		return 0;
	// 	}
		
	// 	ll part1=2*n-m+1;
	// 	// cout<<"part1 "<<part1<<endl;
	// 	ll part2=1;
	// 	// cout<<"part2 "<<part2<<endl;
	// 	ll k=(m+1)/2;
	// 	part2+=n-k;
	// 	n=k;
	// 	part2+=2*n-m;
	// 	// cout<<"part2 "<<part2<<endl;
	// 	ans+=min(part1,part2);
	// 	cout<<ans<<endl;
	// }
	ll ans=recurse(n,m);
	cout<<ans<<endl;
	return 0;
}