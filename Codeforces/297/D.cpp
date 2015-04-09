#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;
typedef pair<int,int> pi;
typedef pair<pi,pi> ppi;
typedef std::vector<int> vi;

int n,m;
std::vector<vi> v(2222,vi(2222,0));

int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

set<pi> DP;

bool check(int x,int y){
	// cout<<"f x "<<x<<" y "<<y<<endl;
	if(x<=0 || x>n || y<=0 || y>m) return 0;
	if(DP.find(pi(x,y))!=DP.end())
		return 0;
	if(v[x][y]!=0) return 0;

	if(v[x-1][y-1]+v[x-1][y]+v[x][y-1]==3) return 1;
	if(v[x+1][y+1]+v[x+1][y]+v[x][y+1]==3) return 1;
	if(v[x+1][y-1]+v[x+1][y]+v[x][y-1]==3) return 1;
	if(v[x-1][y+1]+v[x-1][y]+v[x][y+1]==3) return 1;

	return 0;
}

int main() {

	cin>>n>>m;
	string s;
	for (int i = 1; i <= n; ++i)
	{
		cin>>s;
		for (int j = 1; j <=m ; ++j)
		{
			if(s[j-1]=='*')
				v[i][j]=0;
			else
				v[i][j]=1;
		}
		// cout<<s<<endl;
	}
	// cout<<"---------\n";
	for (int i = 1; i <=n ; ++i)
	{
		for (int j = 1; j <=m ; ++j)
		{
			if(check(i,j)){
				DP.insert(pi(i,j));
			}
		}
	}
	while(DP.size()){
		// cout<<"hi\n";
		pi p=*(DP.begin());
		DP.erase(DP.begin());
		v[p.first][p.second]=1;
		// cout<<"p.first "<<p.first<<" p.sec "<<p.second<<endl;
		for (int i = -1; i <=1 ; ++i){
			for(int j=-1;j<=1;j++){
				int x=p.first+i;
				int y=p.second+j;
				// cout<<"x "<<x<<" y "<<y<<endl;
				if(check(x,y)){
					if(DP.find(pi(i,j))!=DP.end());					
						DP.insert(pi(x,y));
				}
			}
		}
	}
	for (int i = 1; i <= n; ++i)
	{
		string s="";
		for (int j = 1; j <=m ; ++j)
		{
			if(v[i][j]==0)
				s+='*';
			else
				s+='.';
		}
			cout<<s<<endl;
	}
	return 0;
}