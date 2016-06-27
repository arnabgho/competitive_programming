#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;
typedef pair<int,int> pi;
int main() {
	string s;
	cin>>s;
	std::vector<int> v;
	for (int i = 0; i < s.size(); ++i)
	{
		v.push_back(s[i]-'0');
	}
	int ans=0;
	bool f=0;
	std::vector<pi> res;
	while(!f){
		if(accumulate(v.begin(),v.end(),0)==0) {f=1;break;}
		int mn=1e9;
		for (int i = 0; i < v.size(); ++i)
		{
			if(v[i]==0) continue;
			mn=min(mn,v[i]);
		}
		int val=0;
		for (int i = 0; i < v.size(); ++i)
		{
			if(v[i]==0){
				val=val*10;
			}
			else{
				val=val*10+1;
				v[i]-=mn;
			}
		}
		ans+=mn;
		res.push_back(pi(val,mn));
	}
	cout<<ans<<endl;
	for (int i = 0; i < res.size(); ++i)
	{
		for (int j = 0; j < res[i].second; ++j)
		{
			cout<<res[i].first<<" ";
		}
	}
	cout<<endl;
	return 0;
}