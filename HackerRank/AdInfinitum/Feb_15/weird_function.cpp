#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;
typedef long long ll;

map<ll,ll> myMap;

ll phi(ll n){
	if(myMap.find(n)!=myMap.end())
		return myMap[n];
	ll result=n;
	for (ll i = 2; i*i <=n ; ++i)
	{
		if(n%i==0){
			result-=result/i;
		}
		while(n%i==0) n/=i;
	}
	if(n>1)
		result-=result/n;
	return myMap[n]=result;
}

int main() {
	ll T,L,R,i,j;
	cin>>T;
	while(T--){
		cin>>L>>R;
		j=sqrt(8*L+1)-1;
		j/=2;
		// cout<<"j "<<j<<endl;
		while((j*(j+1))/2 <L) j++;
		ll ans=0;
		for (; j*(j+1)/2 <=R ; ++j)
		{
			// ll i=(j*(j+1))/2;
			if(j%2==0)
				ans+=phi(j/2)*phi(j+1);
			else
				ans+=phi(j)*phi((j+1)/2);	 	
		}
		cout<<ans<<endl;
	}
	return 0;
}