#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;

int main() {
	int n;
	int ones=0,zeros=0;
	string s;
	cin>>n;
	cin>>s;
	for (int i = 0; i < s.size(); ++i)
	{
		if(s[i]=='1') ones++;
		else zeros++;
	}
	cout<<abs(ones-zeros)<<endl;
	return 0;
}