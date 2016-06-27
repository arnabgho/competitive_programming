#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;

std::map<string, bool> DP;
bool f=0;
bool recurse(string s){
	if(f) return 1;
	if(!s.size())
		return 1;
	if(DP.count(s))
		return DP[s];
	bool ans=0;
	for (int i = 0; i < s.size(); ++i)
	{
		int streak=1;
		for (int j = i+1; j < s.size(); ++j)
		{
			if(s[j]==s[i])
				streak++;
			else
				break;
		}
		if(streak<2) continue;
		// cout<<"s "<<s<<endl;
		for (int j = i; j < i+streak; ++j)
		{
			for (int l = 2; j+l-1 < i+streak ; ++l)
			{
				string left=s.substr(0,j);
				string right=s.substr(j+l);
				// cout<<"left "<<left<<" right "<<right<<endl;
				ans|=recurse(left+right);
			}
		}
		i+=streak-1;
		// cout<<"-------";
	}
	f|=ans;
	return DP[s]=ans;
}

int main() {
	int t;
	cin>>t;
	for (int cas = 1; cas <=t ; ++cas)
	{
		string s;
		cin>>s;
		f=0;
		DP.clear();
		recurse(s);
		cout<<DP[s]<<endl;
	}
	return 0;
}