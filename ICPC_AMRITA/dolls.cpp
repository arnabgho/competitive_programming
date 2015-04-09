#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;
std::vector<int> v(200);
int main() {
	int t;
	cin>>t;
	for (int cas = 1; cas <= t; ++cas)
	{
		int n;
		cin>>n;
		
		for (int i = 0; i < n; ++i)
		{
			cin>>v[i];
		}
		sort(v.begin(),v.begin()+n);
		bool pos=true;
		for (int i = 0; i < n-1; ++i)
		{
			if(v[i]==v[i+1])
				pos=false;
		}
		if(pos)
			cout<<"YES\n";
		else
			cout<<"NO\n";
	}
	return 0;
}