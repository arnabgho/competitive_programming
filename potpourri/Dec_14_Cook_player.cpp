#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
		double n;
		cin>>n;
		double ans=0.0;
		for (double i = 1.0; i <=n ; i+=1.0)
		{
			ans+=n/i;
		}
		cout<<ans<<endl;
	}	
	return 0;
}