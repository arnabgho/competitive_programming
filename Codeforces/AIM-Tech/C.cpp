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

std::vector<set<int> > G(510);
std::map<PII, int> edges;
int main(){
		
	int n,m;
	cin>>n>>m;
	for (int i = 0; i < m; ++i)
	{
		int u,v;
		cin>>u>>v;
		u--;v--;
		G[u].insert(v);
		G[v].insert(u);
	}	
	std::string assign(n,'-');
	// Assign bs 

	for (int i = 0; i < n; ++i)
	{
		if(G[i].size()==n-1){
			assign[i]='b';
		}
	}
	queue<PII> Q;
	string give="ac";
	for (int i = 0; i < n; ++i)
	{
		if(assign[i]=='-'){
			Q.push(PII(i,0));
			assign[i]=give[0];
			break;
		}
	}
	
	bool conflict=false;
	while(!Q.empty() && !conflict){
		PII p=Q.front();
		Q.pop();
		int u=p.fi;
		// cout<<"u "<<u<<endl;
		// cout<<"assignment "<<assign[u]<<endl;
		int val=p.se;
		int next=(val+1)%2;
		if(assign[u]!='-' && assign[u]!=give[val]){
			// cout<<"Hello\n";
			conflict=true;
			break;
		}

		for (int v = 0; v < n; ++v)
		{
			if(G[u].count(v)==0){
				if(v==u) continue;
				if(assign[v]=='-'){
					Q.push(PII(v,next));
					assign[v]=give[next%2];
				}
				if(assign[v]!='-' && assign[v]!=give[next]){
					// cout<<"v "<<v<<endl;
					conflict=true;
					break;
				}
			}
		}
	}
	if(conflict){
		cout<<"No\n";
		return 0;
	}

	for (int u = 0; u < n; ++u)
	{
		for (set<int>::iterator it = G[u].begin(); it!=G[u].end() ; ++it)
		{
			int v=*it;
			if(assign[u]=='b' && assign[v]=='-'){
				assign[v]='a';
			}
			if(assign[u]=='a' && assign[v]=='-'){
				assign[v]='a';
			}
			if(assign[u]=='c' && assign[v]=='-'){
				assign[v]='c';
			}
		}
	}

	// Check whether current assignment is stable
	for (int i = 0; i < n; ++i)
	{
		for (int j = i+1; j < n; ++j)
		{
			if(G[i].count(j)==0){
				if(assign[i]=='a' && assign[j]=='c') continue;
				if(assign[i]=='c' && assign[j]=='a') continue;
				conflict=true;
			}
			else{
				if(assign[i]=='a' && assign[i]=='c') conflict=true;
				if(assign[i]=='c' && assign[i]=='a') conflict=true;
			}
		}
	}
	// cout<<"Hi\n";
	if(conflict)
		cout<<"No\n";
	else{
		cout<<"Yes\n";
		cout<<assign<<endl;
	}
	return 0;	
}
