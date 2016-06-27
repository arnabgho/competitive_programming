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
map<string,int> DP;
int cur=0;
int getIndex(string s){
	if(DP.count(s))
	   	return DP[s];
	else{
	    DP[s]=cur;
	    cur++;
	}
	
	return DP[s];
}

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
class UnionFind {                                              // OOP style
private:
  vi p, rank, setSize;                       // remember: vi is vector<int>
  int numSets;
public:
  UnionFind(int N) {
    setSize.assign(N, 1); numSets = N; rank.assign(N, 0);
    p.assign(N, 0); for (int i = 0; i < N; i++) p[i] = i; }
  int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
  bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
  void unionSet(int i, int j) { 
    if (!isSameSet(i, j)) { numSets--; 
    int x = findSet(i), y = findSet(j);
    // rank is used to keep the tree short
    if (rank[x] > rank[y]) { p[y] = x; setSize[x] += setSize[y]; }
    else                   { p[x] = y; setSize[y] += setSize[x];
                             if (rank[x] == rank[y]) rank[y]++; } } }
  int numDisjointSets() { return numSets; }
  int sizeOfSet(int i) { return setSize[findSet(i)]; }
};

vector<vii> AdjList;
vi taken;                                  // global boolean flag to avoid cycle
priority_queue<ii> pq;            // priority queue to help choose shorter edges

void process(int vtx) {    // so, we use -ve sign to reverse the sort order
  taken[vtx] = 1;
  for (int j = 0; j < (int)AdjList[vtx].size(); j++) {
    ii v = AdjList[vtx][j];
    if (!taken[v.first]) pq.push(ii(-v.second, -v.first));
} }                                // sort by (inc) weight then by (inc) id


int main(){
	int test;
	cin>>test;
	while(test--){
		int V, E, u, v, w;

  		
	cur=0;
	  scanf("%d %d", &V, &E);
	  // Kruskal's algorithm merged with Prim's algorithm
	  AdjList.assign(V, vii());
	  vector< pair<int, ii> > EdgeList;   // (weight, two vertices) of the edge
	  int cur=0;
	  for (int i = 0; i < E; i++) {
	    // scanf("%d %d %d", &u, &v, &w);            // read the triple: (u, v, w)
	    string s_u,s_v;
	    cin>>s_u>>s_v>>w;
	    u=getIndex(s_u);
	    v=getIndex(s_v);
	    EdgeList.push_back(make_pair(w, ii(u, v)));                // (w, u, v)
	    AdjList[u].push_back(ii(v, w));
	    AdjList[v].push_back(ii(u, w));
	  }
	  sort(EdgeList.begin(), EdgeList.end()); // sort by edge weight O(E log E)
	                      // note: pair object has built-in comparison function

	  int mst_cost = 0;
	  UnionFind UF(V);                     // all V are disjoint sets initially
	  for (int i = 0; i < EdgeList.size(); i++) {                      // for each edge, O(E)
	    pair<int, ii> front = EdgeList[i];
	    if (!UF.isSameSet(front.second.first, front.second.second)) {  // check
	      mst_cost += front.first;                // add the weight of e to MST
	      UF.unionSet(front.second.first, front.second.second);    // link them
	  } }                       // note: the runtime cost of UFDS is very light

	  // note: the number of disjoint sets must eventually be 1 for a valid MST
	  // printf("MST cost = %d (Kruskal's)\n", mst_cost);
	  printf("%d\n",mst_cost );
	}
	return 0;	
}
	