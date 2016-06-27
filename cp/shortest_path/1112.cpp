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

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define INF 1000000000

int V, E, s, u, v, w;
vector<vii> AdjList;

int main(){
	int test;
	cin>>test;
	while(test--){
		int T,Exit;
		cin>>V>>Exit>>T;
		cin>>E;
		AdjList.assign(V+10, vii());
		for (int i = 0; i < E; ++i)
		{
			int u,v,w;
			cin>>u>>v>>w;
			AdjList[v].push_back(PII(u,w));
		}

		vi dist(V, INF); dist[Exit] = 0;                    // INF = 1B to avoid overflow
	  priority_queue< ii, vector<ii>, greater<ii> > pq; pq.push(ii(0, Exit));
	                             // ^to sort the pairs by increasing distance from s
	  while (!pq.empty()) {                                             // main loop
	    ii front = pq.top(); pq.pop();     // greedy: pick shortest unvisited vertex
	    int d = front.first, u = front.second;
	    if (d > dist[u]) continue;   // this check is important, see the explanation
	    for (int j = 0; j < (int)AdjList[u].size(); j++) {
	      ii v = AdjList[u][j];                       // all outgoing edges from u
	      if (dist[u] + v.second < dist[v.first]) {
	        dist[v.first] = dist[u] + v.second;                 // relax operation
	        pq.push(ii(dist[v.first], v.first));
	  } } }  // note: this variant can cause duplicate items in the priority queue

	  int ans=0;
	  for (int i = 1; i <= V; ++i)
	  {
	  	if(dist[i]<=T)
	  		ans++;
	  }
	  cout<<ans<<endl;
	}
	return 0;	
}
