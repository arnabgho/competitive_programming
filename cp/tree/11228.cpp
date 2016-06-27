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

// Union-Find Disjoint Sets Library written in OOP manner, using both path compression and union by rank heuristics
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
} }                            


double getDist(double x1,double y1,double x2,double y2){
	return sqrt( pow(x1-x2,2)+pow(y1-y2,2));
}


int main(){
	int test;
	cin>>test;
	for(int cas=1;cas<=test;cas++){
		int V, E, u, v, w;
		double r;
  		
	  scanf("%d %lf", &V, &r);
	  // Kruskal's algorithm merged with Prim's algorithm
	  // AdjList.assign(V, vii());
	  vector< pair<double, ii> > EdgeList;   // (weight, two vertices) of the edge
	  std::vector<PII> P;
	  for (int i = 0; i < V; ++i)
	  {
	  	PII x;
	  	cin>>x.fi>>x.se;
	  	P.push_back(x);
	  }
	  for (int i = 0; i < V; ++i)
	  {
	  	for (int j = i+1; j <V ; ++j)
	  	{
	  		double d=getDist(P[i].fi,P[i].se,P[j].fi,P[j].se);
	  		EdgeList.push_back(mp(d,ii(i,j)));
	  	}
	  }
	  sort(EdgeList.begin(), EdgeList.end()); // sort by edge weight O(E log E)
	                      // note: pair object has built-in comparison function
	  double mst_cost_road = 0;
	  double mst_cost_rail=0;
	  int states=1;
	  UnionFind UF(V);                     // all V are disjoint sets initially
	  for (int i = 0; i < EdgeList.size(); i++) {                      // for each edge, O(E)
	    pair<double, ii> front = EdgeList[i];
	    if (!UF.isSameSet(front.second.first, front.second.second)) {  // check
	    if(front.first>r){ states++;
	    	mst_cost_rail+=front.first;
	    }	
	    else{
	    mst_cost_road += front.first;
	    }                // add the weight of e to MST
	      UF.unionSet(front.second.first, front.second.second);    // link them
	  } }                       // note: the runtime cost of UFDS is very light

	  // note: the number of disjoint sets must eventually be 1 for a valid MST
	  // printf("MST cost = %d (Kruskal's)\n", mst_cost);
	  int mst_cost_road_int=mst_cost_road;
	  int mst_cost_rail_int=mst_cost_rail;
	  printf("Case #%d: %d %d %d\n",cas,states,mst_cost_road_int,mst_cost_rail_int);
	}
	return 0;	
}
