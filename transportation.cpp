#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;


vector<bool> visited;
std::vector<int> a;

int main() {
	int n,t,x;
	cin>>n>>t;
	a.push_back(0);
	visited.push_back(false);
	for (int i = 1; i < n; ++i)
	{
		cin>>x;
		a.push_back(x);
		visited.push_back(false);
	}
	visited[1]=true;
	for (int i = 1; i <n ; ++i)
	{
		if(visited[i])
			visited[i+a[i]]=true;
	}
	if(visited[t])
		cout<<"YES\n";
	else
		cout<<"NO\n";
	return 0;
}