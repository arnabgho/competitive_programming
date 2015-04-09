#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;

std::vector<int> f(111111,0);

int main() {
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int maxim=0;
		fill(f.begin(), f.end(),0);
		for (int i = 0; i < n; ++i)
		{
			int x;
			cin>>x;
			f[x]++;
			//cout<<"f[x] "<<f[x]<<endl;
			maxim=max(maxim,f[x]);
		}
		cout<<n-maxim<<endl;
	}
	return 0;
}