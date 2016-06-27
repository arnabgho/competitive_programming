#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;
std::vector<string> v;
int main() {
	string s;
	cin>>s;
	int n=s.size();
	int res=-1;
	for (int i = 0; i <n ; ++i)
	{
		int x=0;
		x=s[i]-'0';
		// cout<<"x "<<x<<endl;
		if(x%8==0)
			res=x;
	} 
	if(res!=-1){cout<<"YES\n"<<res<<endl;return 0;}
	// 2 digit
	// cout<<"---------\n";
	for (int i = 0; i <n ; ++i)
	{
		for (int j = i+1; j < n; ++j)
		{
			int x=0;
			x=s[i]-'0';
			x=x*10+s[j]-'0';
			// cout<<"x "<<x<<endl;
			if(x%8==0)
				res=x;
		}
	} 
	if(res!=-1){cout<<"YES\n"<<res<<endl;return 0;}
	//3 digit
	for (int i = 0; i <n ; ++i)
	{
		for (int j = i+1; j < n; ++j)
		{
			for (int k = j+1; k <n ; ++k)
			{
				int x=0;
				x=s[i]-'0';
				x=x*10+s[j]-'0';
				x=x*10+s[k]-'0';
				// cout<<"x "<<x<<endl;
				if(x%8==0)
					res=x;
			}
		}
	} 
	if(res!=-1){cout<<"YES\n"<<res<<endl;return 0;}
	if(res==-1)
		cout<<"NO\n";
	return 0;
}