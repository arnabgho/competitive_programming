#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
#define fi first
#define se second
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
const ll mod=1000000007;
ll powmod(ll a,ll b) {ll res=1;a%=mod;for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
// head

std::map<PII,ll> DP;

bool can_visit(int i,int j){
	if(i==j) 
		return false;
	if(i==4)
		return true;
	if(i==3){
		if(j==5) return false;
		else return true;
	}
	if(i==5){
		if(j==3) return false;
		else return true;
	}
	if(i==1){
		if(j==7) return false;
		else return true;
	}
	if(i==7){
		if(j==1) return false;
		else return true;
	}
	if(i==0){
		if(j==2 || j==6 || j==8) return false;
		else return true;
	}
	if(i==2){
		if(j==0 || j==6 || j==8) return false;
		else return true;
	}
	if(i==6){
		if(j==2 || j==0 || j==8) return false;
		else return true;
	}
	if(i==8){
		if(j==2 || j==6 || j==0) return false;
		else return true;
	}
}

ll recurse(int cur,int visited){
	for (int i = 0; i < 9; ++i)
	{
		if(visited==(1<<i) && can_visit(cur,i))
			return 1;
	}
	if(visited==(1<<9)-1 || visited==0)
		return 0;
	for (int i = 0; i < 9; ++i)
	{
		if(i==cur) continue;
		if((visited & (1<<i)) !=0){
			if(can_visit(cur,i)){
				cout<<"cur "<<cur<<" i "<<i<<endl;
				DP[PII(cur,visited)]+= recurse(i,visited-(1<<i));
			}
		}
	}
	return DP[PII(cur,visited)];
}

int main(){
	DP[PII(0,0)]=0;
	for (int i = 0; i < 9; ++i)
	{
		recurse(i,(1<<9)-1-(1<<i));
	}
	ll ans=0;
	for (map<PII,ll>::iterator it = DP.begin();it!=DP.end(); ++it)
	{
		ans+=it->second;
	}
	cout<<"Total Combinations : "<<ans<<endl;
	return 0;	
}
