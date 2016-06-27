#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;

int getStreak(std::vector<int> v){
	int n=1;
	for (int i = 0; i+1 <v.size() ; ++i)
	{
		if(v[i+1]==v[i]+1)
			n++;
		else
			break;
	}
	return n;
}

int main() {
	int n,k;
	cin>>n>>k;
	int nComp=0;
	int ans=0;
	for (int i = 0; i < k; ++i)
	{
		int m;
		std::vector<int> v;
		cin>>m;
		for (int i = 0; i < m; ++i)
		{
			int x;
			cin>>x;
			v.push_back(x);
		}
		if(v[0]==1){
			int streak=getStreak(v);
			nComp+=m-streak+1;
			ans+=m-streak;
		}
		else{
			nComp+=m;
			ans+=m-1;
		}
	}
	cout<<ans+nComp-1<<endl;
	return 0;
}