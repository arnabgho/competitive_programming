#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;
vector<string> in;
std::vector<string> res;
int main() {
	int m,n;
	cin>>n>>m;
	string s="";
	for (int i = 0; i < n; ++i)
	{
		cin>>s;
		in.push_back(s);
		res.push_back("");
	}
	int ans=0;
	bool first=false;
	for (int i = 0; i < m; ++i)
	{
		bool found=false;
		for (int j = 1; j <n && !found ; ++j)
		{
			string s1=res[j]+in[j][i];
			string s2=res[j-1]+in[j-1][i];
			if(s1<s2){
				found=true;
			}
		}
		if(found)
			ans++;
		else{
			for (int k = 0; k < n; ++k)
			{
				res[k]+=in[k][i];
			}
		}
	}

	cout<<ans<<endl;
	return 0;
}