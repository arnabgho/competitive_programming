#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;
map<string,int> DP;
int main() {
	int n;
	cin>>n;
	int ans=1;
	for (int i = 0; i <n ; ++i)
	{
		string s;
		cin>>s;
		DP[s]++;
		ans=max(ans,DP[s]);
	}
	cout<<ans<<endl;
	return 0;
}