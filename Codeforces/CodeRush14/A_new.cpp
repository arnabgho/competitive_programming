#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;
typedef pair<int,int> pi;
std::vector<pi> v[2];
std::vector<pi> s[2];

int main() {
	int n,x;
	int t,h,m;
	cin>>n>>x;
	for (int i = 0; i < n; ++i)
	{
		cin>>t>>h>>m;
		v[t].push_back(pi(m,h));
		s[t].push_back(pi(m,h));
	}

	int mx0=0;
	int cur=x;
	int turn=0;

	while(1){
		if(s[turn].size()==0)
			break;
		bool f=0;
		int maxpos=-1;
		int mx=0;
		for (int i = 0; i < s[turn].size(); ++i)
		{
			if(s[turn][i].second<=cur){
				f=1;
				if(s[turn][i].first>mx){
					mx=s[turn][i].first;
					maxpos=i;
				}
			}
		}
		if(!f) break;
		mx0++;
		cur+=s[turn][maxpos].first;
		s[turn].erase(s[turn].begin()+maxpos);
		turn=(turn+1)%2;
	}

	s[0]=v[0];s[1]=v[1];

	int mx1=0;
	cur=x;
	turn=1;

	while(1){
		if(s[turn].size()==0)
			break;
		bool f=0;
		int maxpos=-1;
		int mx=0;
		for (int i = 0; i < s[turn].size(); ++i)
		{
			if(s[turn][i].second<=cur){
				f=1;
				if(s[turn][i].first>mx){
					mx=s[turn][i].first;
					maxpos=i;
				}
			}
		}
		if(!f) break;
		mx1++;
		cur+=s[turn][maxpos].first;
		s[turn].erase(s[turn].begin()+maxpos);
		turn=(turn+1)%2;
	}


	cout<<max(mx0,mx1)<<endl;
	return 0;
}