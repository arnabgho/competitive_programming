#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;
typedef unsigned long long int ll;
std::map<ll, ll> DP;

ll recurse(ll n,ll back){
	if(n<=1) return 0;
	if(DP.count(n)) return DP[n];
	ll sum=0;
	for (ll i = 1; i <=back ; ++i)
	{
		if(n>=i)
			sum+=1+recurse(n-i,back);
		else
			sum++;	 	
	} 
	return DP[n]=sum;
}

int main() {
	ll n,m;
	cin>>n>>m;
	while(n<=60){
		DP.clear();
		cout<<recurse(n,m)+1<<endl;
		cin>>n>>m;
	}
	return 0;
}