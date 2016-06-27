#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;

std::vector<bool> v(4e6,1);	

int main() {
	int n,k;
	cin>>n>>k;
	for (int i = 0; i < k; ++i)
	{
		int x;
		cin>>x;
		v[x]=0;
		v[x-1]=0;
		v[x+1]=0;
	}
	int ans=k;
	for (int i = 1; i <=n ; ++i)
	{
		if(v[i]){
			ans++;
			v[i+1]=0;
		}
	}
	cout<<ans<<endl;
	return 0;
}