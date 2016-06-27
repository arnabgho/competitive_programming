#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;
typedef long long ll;
int main() {
	ll k,n,w;
	cin>>k>>n>>w;
	ll ans=k*((w+1)*w)/2 -n ;
	if(ans<=0)
		cout<<"0\n";
	else
		cout<<ans<<endl;
	return 0;
}