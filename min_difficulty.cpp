#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;

std::vector<int> v;

int main() {
	int n,num,ans=1e9;
	cin>>n;cas
	for (int i = 0; i < n; ++i)
	{
		cin>>num;
		v.push_back(num);
	}
	for (int i = 1; i < n-1; ++i)
	{
		int maxdiff=0;
		for (int j = 1; j < n; ++j)
		{
			if(j!=i)
				maxdiff=max(maxdiff,v[j]-v[j-1]);
			else{
				maxdiff=max(maxdiff,v[j+1]-v[j-1]);
				j++;
			}
		}
		ans=min(ans,maxdiff);
	}
	cout<<ans<<endl;
	return 0;
}