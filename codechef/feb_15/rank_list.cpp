#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;

typedef long long ll;

int main() {
	int t;
	cin>>t;
	while(t--){
		ll n,s;
		cin>>n>>s;
		ll disc=sqrt((2*n+1)*(2*n+1)-8*s);
		ll k=((2*n+1)-disc)/2;
		ll ans=k;
		for (; k <=n ; ++k)
		{
			if(2*k*n-k*k+k<=2*s)
				ans=k;
			else
				break;
		}
		cout<<n-ans<<endl;
	}
	return 0;
}