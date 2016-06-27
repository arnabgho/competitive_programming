#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;
std::vector<int> v;
int main() {
	int n;
	cin>>n;
	for (int i = 0; i < n; ++i)
	{
		int x;cin>>x;
		v.push_back(x);
	}
	int minim=v[0];
	int maxim=v[n-1];
	int mn,mx;
	for (int i = 0; i < n; ++i)
	{
		if(i==0){
			mn=v[i+1]-v[i];
			mx=maxim-v[i];
		}
		else if(i==n-1){
			mn=v[i]-v[i-1];
			mx=v[i]-minim;
		}
		else{
			mn=min(v[i]-v[i-1],v[i+1]-v[i]);
			mx=max(maxim-v[i],v[i]-minim);
		}
		cout<<mn<<" "<<mx<<endl;
	}
	return 0;
}