#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;
std::vector<int> v_AB;
std::vector<int> v_BA;
int main() {
	string s;
	cin>>s;
	string ab,ba;
	ab="AB";
	ba="BA";
	int n=s.size();
	for (int i = 0; i+1 <n ; ++i)
	{
		string n=s.substr(i,2);
		if(n.compare(ab)==0)
			v_AB.push_back(i);
		if(n.compare(ba)==0)
			v_BA.push_back(i);
	}
	bool f=0;
	for (int i = 0; i < v_AB.size() && !f; ++i)
	{
		for (int j = 0; j < v_BA.size() && !f; ++j)
		{
			if(abs(v_AB[i]-v_BA[j])!=1)
				f=1;
		}
	}
	if(f)
		cout<<"YES\n";
	else
		cout<<"NO\n";
	return 0;
}