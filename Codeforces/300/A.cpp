#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;

int main() {
	string s;
	cin>>s;
	string c="CODEFORCES";
	int pos=0;
	bool f=0;
	for (int i = 0; i < s.size(); ++i)
	{
		string left=s.substr(0,i);
		for (int j = 0; i+j <=s.size() ; ++j)
		{
			string right=s.substr(i+j);
			if(c.compare(left+right)==0) f=1;
		}
	}
	if(f) cout<<"YES\n";
	else cout<<"NO\n";
	return 0;
}