#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;

int main() {
	int t,n;
	cin>>t;
	while(t--){
		cin>>n;
		for (int i = 0; i < 2*n; ++i)
		{
			int joke;
			cin>>joke;
		}
		int ans=0;
		for (int i = 1; i <= n; ++i)
		{
			ans=ans^i;
		}
		cout<<ans<<endl;
	}
	return 0;
}