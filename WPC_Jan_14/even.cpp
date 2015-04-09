#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;
typedef long long ll;
int main() {
	int t;
	cin>>t;
	while(t--){
		ll e,o;
		cin>>e>>o;
		if((e+o)%5 !=0)
			cout<<"-1\n";
		else{
			cout<<abs((2*e+2*o)/5-e)<<endl;
		}
	}
	return 0;
}