#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;

std::vector<int> v;
int main() { 
	int n,k,i,a;
	cin>>n>>k;
	for(i=0;i<n;i++){
		cin>>a;
		v.push_back(a);
	}
	sort(v.begin(),v.end());
	int ans=0,b;
	for(i=0;i<n;i++){
		b=5-v[i];
		if(b>=k) ans++;
	}
	cout<<ans/3<<endl;
	return 0;
}