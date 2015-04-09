#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;
typedef long long ll;
typedef pair<ll,ll> PL;
typedef pair<PL,ll> PLL; 
map<PLL,ll> DP;
std::vector<int> A;

ll fact[20];
ll n;
void compute(){
	fact[0]=1;
	for (int i = 1; i < 19; ++i)
	{
		fact[i]=i*fact[i-1];
		// cout<<"fact "<<fact[i]<<endl;
	}
}

ll recursive(ll cur,ll k,ll S){
	if(S<0) return 0;
	if(S==0) return 1;
	if(cur==n && S==0) return 1;
	if(cur==n && S!=0) return 0;
	PL pl=PL(cur,k);
	PLL pll=PLL(pl,S);
	if(DP.find(pll)!=DP.end())
		return DP[pll];
	ll ans=recursive(cur+1,k,S);
	if(A[cur]<=S)
		ans+=recursive(cur+1,k,S-A[cur]);
	if(k>0){
		// cout<<"A[cur] "<<A[cur]<<" fact "<<fact[A[cur]]<<endl;
		if(A[cur]<19 && fact[A[cur]]<=S)
			ans+=recursive(cur+1,k-1,S-fact[A[cur]]);
	}
	// cout<<"cur "<<cur<<" k "<<k<<" S "<<S<<endl;
	// cout<<"ans "<<ans<<endl;
	return DP[pll]=ans;
}

int main() {
	compute();
	ll k,S;
	cin>>n>>k>>S;
	for (int i = 0; i <n; ++i)
	{
		ll x;
		cin>>x;
		A.push_back(x);
	}
	sort(A.begin(),A.end());
	ll ans=recursive(0,k,S);
	cout<<ans<<endl;
	return 0;
}