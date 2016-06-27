#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;
typedef pair<int,int> pi;
std::vector<pi> v;
int main() {
	int n,m;
	cin>>n>>m;
	for (int i = 0; i < m; ++i)
	{
		int x,y;
		cin>>x>>y;
		v.push_back(pi(x,y));
	}
	bool pos=1;
	for (int i = 0; i+1 < v.size(); ++i)
	{
		if(abs(v[i].second-v[i+1].second)>abs(v[i].first-v[i+1].first) ) pos=0;
	}
	if(!pos){
		cout<<"IMPOSSIBLE\n";
		return 0;
	}
	int mx=max( v[0].second+ (v[0].first-1),v[m-1].second+(n-v[m-1].first ) );
	for (int i = 0; i+1 <v.size() ; ++i)
	{
		mx=max(mx,(v[i].second+v[i+1].second)/2+abs(v[i].first-v[i+1].first)/2);
	}
	cout<<mx<<endl;
	return 0;
}