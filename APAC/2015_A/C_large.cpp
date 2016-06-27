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

int dist[200][200];
int G[200][200];
std::vector<PII> Edges;
void init(){
	for (int i = 0; i < 200; ++i)
	{
		for (int j = 0; j < 200; ++j)
		{
			dist[i][j]=1e9;
			G[i][j]=1e9;
		}
	}
	Edges.clear();
}

int main(){
	int test;
	cin>>test;
	for (int cas = 1; cas <=test ; ++cas)
	{
		init();
		int n,m;
		cin>>n>>m;
		for (int i = 0; i < m; ++i)
		{
			int u,v,t;
			cin>>u>>v>>t;
			dist[u][v]=t;
			dist[v][u]=t;
			G[u][v]=t;
			G[v][u]=t;
			Edges.push_back(PII(u,v));
		}
		// Floyd Warshall
		for (int k = 0; k < n; ++k)
		{
			for (int i = 0; i < n; ++i)
			{
				for (int j = 0; j < n ; ++j)
				{
					if(i==j) continue;
					dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
				}
			}
		}
		for (int i = 0; i < n; ++i)
		{
			dist[i][i]=0;
		}
		// for (int i = 0; i < n; ++i)
		// {
		// 	for (int j = 0; j < n; ++j)
		// 	{
		// 		cout<<dist[i][j]<<" ";
		// 	}
		// 	cout<<endl;
		// }
		printf("Case #%d:\n",cas );
		for (int i = 0; i < Edges.size(); ++i)
		{
			int u=Edges[i].fi;
			int v=Edges[i].se;
			bool pos=0;
			for (int a = 0; a < n && !pos; ++a)
			{
				for (int b = 0; b < n && !pos ; ++b)
				{
					if(a==b) continue;
					if((a==u && b==v) || (b==u && a==v) ) continue;
					// cout<<"a "<<a<<" b "<<b<<" u "<<u<<" v "<<v<<endl;
					// cout<<"dist[a][u] "<<dist[a][u]<<endl;
					// cout<<"dist[v][b] "<<dist[v][b]<<endl;
					// cout<<"dist[u][v] "<<G[u][v]<<endl;
					// cout<<"dist[a][b] "<<dist[a][b]<<endl;
					if(dist[a][u]+dist[v][b]+G[u][v]==dist[a][b])
						pos=1;
				}
			}
			// cout<<"pos "<<pos<<endl;
			if(!pos)
				cout<<i<<" ";
		}
		cout<<endl;
	}
	return 0;	
}