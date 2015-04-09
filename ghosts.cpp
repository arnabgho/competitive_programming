#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;

std::vector<int> v(2000);
std::vector<int> w(1000);
const int off=1000;
int main() {
	int m,t,r;
	cin>>m>>t>>r;
	for (int i = 0; i < m; ++i)
	{
		cin>>w[i];
	}
	bool pos=1;
	for (int i = 0; i < m && pos; ++i)
	{
		int count=0;
		for (int j = w[i]-1; j >= w[i]-t; --j)
		{
			count+=v[j+off];
		}
		// cout<<"w[i] "<<w[i]<<endl;
		// cout<<"count "<<count<<endl;
		if(count>=r) continue;
		for (int j = w[i]-1; j >= w[i]-t; --j)
		{
			if(v[j+off]==0){
				v[j+off]=1;
				// cout<<"j "<<j<<endl;
				// cout<<v[j+off]<<endl;
				count++;
			}
			if(count==r) break;
		}
		if(count<r) pos=0;
	}
	if(!pos)
		cout<<"-1\n";
	else{
		int ans=accumulate(v.begin(), v.end(),0);
		cout<<ans<<endl;	
	}
	return 0;
}