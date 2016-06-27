#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;
typedef std::vector<int> vi;
std::vector<vi> G(110);
void init(){
	for(int i=0;i<110;i++) G[i].clear();
}
int n;
std::vector<bool> valid(110);
std::vector<bool> visited(110);
int res[110][110];

void dfs(int u){
	if(visited[u]||!valid[u])
		return;
	visited[u]=1;
	for (auto v:G[u])
	{
		if(valid[v])
			dfs(v);
	}
}

int main() {
	int t;
	cin>>t;
	for (int cas = 1; cas <=t ; ++cas)
	{
		init();
		cin>>n;
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				int x;cin>>x;
				if(x) G[i].push_back(j);
			}
		}

		fill(valid.begin(), valid.end(),1);
		memset(res,-1,sizeof(res));
		cout<<"+";
		for(int j=0;j<2*n-1;j++) cout<<"-";
		cout<<"+\n";
		for (int i = 0; i <n ; ++i)
		{
			fill(visited.begin(), visited.end(),0);
			valid[i]=0;
			dfs(0);
			for (int j = 0; j < n; ++j)
			{

				if(!visited[j] || j==i)
					cout<<"|Y";
				else
					cout<<"|N";
			}
			cout<<"|\n";
			cout<<"+";
			for(int j=0;j<2*n-1;j++) cout<<"-";
			cout<<"+\n";	
			valid[i]=1;
		}
	}
	return 0;
}