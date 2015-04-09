#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;
typedef long long ll;
typedef pair<ll,ll> pl;
const long long INF = (long long) 1e12;
const int MAXN = 1050;

long long e[MAXN][MAXN];
long long dist[MAXN];
bool used[MAXN];
long long parent[MAXN];

typedef std::vector<int> vi;
std::vector<vi> g(1050);

std::vector<string> v[1050];
ll n,m;
ll k,w;
ll getDiff(ll x,ll y){
	ll ans=0;
	for (ll i = 0; i <n ; ++i)
	{
		for (ll j = 0; j < m; ++j)
		{
			ans+=v[x][i][j]!=v[y][i][j];
		}
	}
	return w*ans;
}

int main() {
	cin>>n>>m>>k>>w;
	for (ll l = 0; l < k; ++l)
	{
		for (ll i = 0; i < n; ++i)
		{
			string s;
			cin>>s;
			v[l].push_back(s);
		}
	}
	ll ans=0;
	for (int i = 0; i <=k; ++i)
	{
		for(int j=0;j<=k;j++)
			e[i][j]=INF;
	}
	for (ll i = 1; i <= k; ++i)
	{
		for (ll j = 1; j <= k; ++j)
		{
			if(i==j) continue;
			e[i][j]=getDiff(i-1,j-1);
		}
	}
	// e[0][1]=e[1][0]=n*m;
	for (int i = 1; i <= k; ++i)
	{
		e[0][i]=e[i][0]=n*m;
	}
	dist[0] = 0;
	for (int i = 1; i <= k; i++){
		parent[i]=0;
		dist[i] = INF;
	}

	// memset(used,0,sizeof(used));
	std::vector<pl> res;
	for (int i = 0; i <= k; i++) {
		int cur = -1;
		for (int j = 0; j <= k; j++)
			if (!used[j] && (cur == -1 || dist[j] < dist[cur])) {
				cur = j;
			}

		used[cur] = true;
		// g[parent[cur]].push_back(cur);
		ans += dist[cur];
		res.push_back(pl(cur,parent[cur]));

		for (int j = 0; j <= k; j++) {
			if (used[j])
				continue;
			if (dist[j] > e[cur][j]){
				dist[j] = e[cur][j];
				parent[j]=cur;
			}
		} 
	}                       	
	cout<<ans<<endl;

	for (int i = 1; i < res.size(); ++i)
	{
		cout<<res[i].first<<" "<<res[i].second<<endl;
	}

	return 0;
}