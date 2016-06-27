#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;

typedef pair<int,int> pi;
std::vector<pi> v;
std::vector<pi> edges;
int main() {
	int n;
	cin>>n;
	int k=-1;
	queue<int> myQ;
	for (int i = 0; i < n; ++i)
	{
		int d,x;
		cin>>d>>x;
		if(d==1){
			myQ.push(i);
			k=i;
		}
		v.push_back(make_pair(d,x));
	}
	if(k==-1){
		cout<<"0\n";
		return 0;
	}
	while(!myQ.empty()){
		int x=myQ.front();
		myQ.pop();
		if(v[x].first!=1)
			continue;
		int y=v[x].second;
		// cout<<" x "<<x<<" y "<<y<<endl;
		edges.push_back(make_pair(x,y));
		v[y].first=v[y].first-1;
		v[y].second=v[y].second ^ x;
		if(v[y].first==1){
			myQ.push(y);
		}
	}
	cout<<edges.size()<<endl;
	for (int i = 0; i < edges.size(); ++i)
	{
		cout<<edges[i].first<<" "<<edges[i].second<<endl;
	}
	return 0;
}