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
std::map<string, int> St;
int n;
std::vector< VI > G;
std::vector<string> L(10010);
int IN;

int getIN(string s){
	if(St.count(s))
		return St[s];
	IN++;
	return St[s]=IN;
}
bool vis[10010];
vector<int> parent(10010);
vector<int> child(10010);


void dfs(int u){
	if(vis[u])
		return ;
	vis[u]=1;
	for(auto v:G[u]){
		child[u]=v;
		parent[v]=u;
		dfs(v);
	}
}


int main(){
	int test;
	cin>>test;
	for (int cas = 1; cas <=test ; ++cas)
	{
		St.clear();
		memset(vis,0,sizeof(vis));
		fill(L.begin(), L.end(),"");
		fill(parent.begin(), parent.end(),-1);
		fill(child.begin(), child.end(),-1);
		cin>>n;
		G.assign(n+10,VI());
		IN=0;
		for (int i = 0; i < n; i++)
		{
			string s1,s2;
			cin>>s1>>s2;
			int u=getIN(s1);
			int v=getIN(s2);
			L[u]=s1;
			L[v]=s2;
			G[u].push_back(v);
		}
		for (int i = 1; i <= IN; ++i)
		{
			if(!vis[i])
				dfs(i);
		}
		int start=-1;
		for (int i = 1; i <=IN ; ++i)
		{
			if(parent[i]==-1){
				start=i;
				break;
			}
		}
		printf("Case #%d: ",cas );
		while(child[start]!=-1){
			cout<<L[start]<<"-"<<L[child[start]]<<" ";
			start=child[start];
		}

		cout<<endl;
	}
	return 0;	
}
