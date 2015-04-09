#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;

std::unordered_map<string, int> mymap;
int main() {
	char l[3]={'a','b','c'};
	int n,m;
	cin>>n>>m;
	for (int i = 0; i < n; ++i)
	{
		string s;
		cin>>s;
		mymap[s]=1;
	}

	for (int i = 0; i < m; ++i)
	{
		string x;
		cin>>x;
		bool f=0;
		for (int j = 0; j < x.size() && !f ; ++j)
		{
			string b=x;
			for (int k = 0; k <3 && !f; ++k)
			{
				if(l[k]==x[j]) continue;
				b[j]=l[k];
				if(mymap.find(b)!=mymap.end())
					f=1;
			}
		}
		if(f)
			cout<<"YES\n";
		else
			cout<<"NO\n";
	}

	return 0;
}