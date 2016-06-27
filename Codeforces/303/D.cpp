#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;
std::vector<int> v;
int main() {
	int n;
	cin>>n;
	for (int i = 0; i < n; ++i)
	{
		int x;
		cin>>x;
		v.push_back(x);
	}
	sort(v.begin(), v.end());
	int ans=0;
	int t=0;
	for (int i = 0; i <n ; ++i)
	{
		// cout<<"t "<<t<<" v[i] "<<v[i]<<endl;
		if(t>v[i]){ans++;continue;}
		// while(t+v[i]>=v[i+1]){ans++; i++;}
		t+=v[i];

	}
	cout<<n-ans<<endl;
	return 0;
}