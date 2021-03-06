#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;

//char mp[51][51];
bool vis[51][51];
std::vector<string> mp;
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
int n,m;
bool dfs(int x,int y,int px,int py,char c){
	vis[x][y]=1;
	for (int i = 0; i < 4; ++i)
	{
		int tx=x+dx[i];
		int ty=y+dy[i];
		if(tx==px && ty==py) continue ;
		if(tx>=0 && tx<n && ty>=0 && ty<m && mp[tx][ty]==c) {
			if(vis[tx][ty]) return 1;
			if(dfs(tx,ty,x,y,c)) return 1;
		}
	}
	return 0;
}


int main(){
	cin>>n>>m;
	for (int i =0 ; i <n ; ++i)
	{
		string s;
		cin>>s;
		mp.push_back(s);
	}
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if(!vis[i][j]){
				if(dfs(i,j,-1,-1,mp[i][j])){
					cout<<"Yes\n";return 0;
				}
			}
		}
	}
	cout<<"No\n";
	return 0;
}