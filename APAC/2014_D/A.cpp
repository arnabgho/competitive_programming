#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
#define fi first
#define se second
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
const ll mod=1000000007;
ll powmod(ll a,ll b) {ll res=1;a%=mod;for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
// head

int board[1010][1010];
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

vector<PII> Store(1000010);
bool vis[1000010];
int numVis[1000010];
int n;
bool isValid(int i,int j){
	return 0<=i && i<n && 0<=j && j<n;
}

int dfs(int u){
	if(vis[u])
		return numVis[u];
	vis[u]=1;
	int x,y;
	x=Store[u].fi;
	y=Store[u].se;
	numVis[u]=1;
	for (int i = 0; i < 4; ++i)
	{
		if(isValid(x+dx[i],y+dy[i]) && board[x+dx[i]][y+dy[i]]==board[x][y]+1){
			numVis[u]+=dfs(board[x+dx[i]][y+dy[i]]);
		}
	}
	return numVis[u];
}


int main(){
	int test;
	cin>>test;
	for (int cas = 1; cas <=test ; ++cas)
	{
		cin>>n;
		memset(board,0,sizeof(board));
		memset(vis,0,sizeof(vis));
		memset(numVis,0,sizeof(numVis));
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				cin>>board[i][j];
				Store[board[i][j]]=PII(i,j);
			}
		}
		int best=-1;
		int best_pos=-1;

		for (int i = 1; i <=n*n ; ++i)
		{
			if(!vis[i])
				dfs(i);
			// cout<<" numVis "<<numVis[i]<<endl;
			if(numVis[i]>best){
				best=numVis[i];
				best_pos=i;
			}
		}
		printf("Case #%d: %d %d\n",cas,best_pos,best );
	}
	return 0;	
}