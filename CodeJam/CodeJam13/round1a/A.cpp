#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;
typedef long long ll;

bool check(ll n,ll t,ll r){
	return 2*n*n+(2*r-1)*n<=t;
}

int main() {
	ll T;
	cin>>T;
	for (ll cas = 1; cas <=T ; ++cas)
	{
		ll r,t;
		cin>>r>>t;
		ll left=0,right=1;
		while(check(right,t,r)){
			left=right;
			right*=2;
		}

		ll lo=left,hi=right;
		ll res=0,dt=t;
		while (lo < hi){
	    	ll mid = lo + (hi-lo)/2;
	    	if (!check(mid,t,r)){
	        	hi = mid;
	    	}
	    	else{
	        	lo = mid+1;
	        	res=max(res,mid);
	    	}
     	}
     	
     	cout<<"Case #"<<cas<<": "<<res<<endl;
	}
	return 0;
}