#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;
typedef std::vector<int> vi;
std::vector<vi> g(111111);
int main() {
	int n,m;
	cin>>n>>m;
	for (int i = 0; i < m; ++i)
	{
		int u,v;
		cin>>u>>v;
		g[u].push_back(v);
	}
	
	return 0;
}