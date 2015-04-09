#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;
std::map<string, string> DP;
int main() {
	int n,m;
	cin>>n>>m;
	for (int i = 0; i < m; ++i)
	{
		string s1,s2;
		cin>>s1>>s2;
		// cout<<"s1 "<<s1<<"s2 "<<s2<<endl;
		DP[s1]=s2;
	}
	for (int i = 0; i < n; ++i)
	{
		string s1,s2;
		cin>>s1;
		s2=DP[s1];
		if(s2.size()<s1.size())
			cout<<s2<<" ";
		else
			cout<<s1<<" ";
	}
	return 0;
}