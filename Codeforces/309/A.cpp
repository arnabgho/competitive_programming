#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;
std::vector<bool> v(26);
int main() {
	string s;
	cin>>s;
	for (int i = 0; i < s.size(); ++i)
	{
		v[s[i]-'a']=1;
	}
	int n=accumulate(v.begin(),v.end(),0);
	cout<<26*(n+1)-(n)<<endl;
	return 0;
}