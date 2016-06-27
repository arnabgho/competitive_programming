#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;
std::vector<string> P(100);
int main() {
	int n,m;
	cin>>n>>m;
	for (int i = 0; i < n; ++i)
	{
		cin>>P[i];
	}
	string test="acef";
	int ans=0;
	for (int i = 0; i+1 < n; ++i)
	{
		for (int j = 0; j+1 <m ; ++j)
		{
			string n="";
			n+=P[i][j];
			n+=P[i+1][j];
			n+=P[i][j+1];
			n+=P[i+1][j+1];
			sort(n.begin(),n.end());
			ans+=test.compare(n)==0;
			// cout<<"n "<<n<<endl;
		}
	}
	cout<<ans<<endl;
	return 0;
}