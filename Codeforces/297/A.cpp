#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;
map<char,int> memo;
int main() {
	int n;
	string s="";
	cin>>n>>s;
	int ans=0;
	for (int i = 0; i < s.size(); i+=2)
	{
		memo[s[i]]++;
		char c=tolower(s[i+1]);
		if(memo[c]>0)
			memo[c]--;
		else
			ans++;
	}
	cout<<ans<<endl;
	return 0;
}