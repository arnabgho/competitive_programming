#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;
typedef long long ll;
const ll INF = 1e18;
typedef pair<ll,ll> PII;
map<PII,PII> ID;
int main(){
  
  ll N, M,s;
  // scanf ("%d%d%d", &N, &s, &t);
  cin>>N>>M;
  vector<vector<PII> > edges(N+1);
  // for (ll i = 0; i < N; i++){
  //   ll M;
  //   scanf ("%d", &M);
  //   for (ll j = 0; j < M; j++){
  //     ll vertex, dist;
  //     scanf ("%d%d", &vertex, &dist);
  //     edges[i].push_back (make_pair (dist, vertex)); // note order of arguments here
  //   }
  // }
  // cout<<"Hi\n";
  // cout<<"N "<<N<<" M "<<M<<endl;
  for (ll i = 0; i < M; ++i)
  {
    // cout<<"Hello\n";
    ll u,v,w;
    cin>>u>>v>>w;
    // cout<<"u "<<u<<" v "<<v <<" w "<<w<<endl;
    edges[u].push_back(PII(w,v));
    edges[v].push_back(PII(w,u)); 
    ID[PII(u,v)]=PII(i+1,w);
    ID[PII(v,u)]=PII(i+1,w);
  }
  cin>>s;
  // cout<<"s "<<s<<endl;
  // cout<<"Hello\n";
  // use priority queue in which top element has the "smallest" priority
  priority_queue<PII, vector<PII>, greater<PII> > Q;
  vector<ll> dist(N+1, INF), dad(N+1, -1) ;
  std::vector<set< ll > > child(N+1);
  Q.push (make_pair (0, s));
  dist[s] = 0;
  std::vector<bool> visited(N+1,0);
  while (!Q.empty()){
    PII p = Q.top();
    // if (p.second == t) break;
    Q.pop();
    
    ll here = p.second;
    if(visited[here]) continue;
    visited[here]=1;
    for (vector<PII>::iterator it=edges[here].begin(); it!=edges[here].end(); it++){
      if(dist[here]+it->first==dist[it->second]){
        if(dad[it->second]==-1) continue;
        ll u=dad[it->second];
        ll v=here;
        if(it->first<ID[PII(u,it->second)].second){
          dad[it->second]=v;
          child[u].erase(child[u].find(it->second));
          child[v].insert(it->second);
        }
      }
      if (dist[here] + it->first < dist[it->second]){
        dist[it->second] = dist[here] + it->first;
        ll u=dad[it->second];
        ll v=here;
        dad[it->second] = here;
        Q.push (make_pair (dist[it->second], it->second));
        child[v].insert(it->second);
        if(u==-1) continue;
        child[u].erase(child[u].find(it->second));
      }
    }
  }
  // cout<<"HI\n";
  // prllf ("%d\n", dist[t]);
  // if (dist[t] < INF)
  //   for(ll i=t;i!=-1;i=dad[i])
  //     prllf ("%d%c", i, (i==s?'\n':' '));
  ll ans=0;
  queue<ll> Qu;
  Qu.push(s);
  std::vector<ll> answer;
  while(!Qu.empty()){
    ll u=Qu.front();
    Qu.pop();
    // cout<<"u "<<u<<endl;
    for(set<ll>::iterator it=child[u].begin();it!=child[u].end();++it ){
      ll v=*it;
      ans+=ID[PII(u,v)].second;
      answer.push_back(ID[PII(u,v)].first);
      Qu.push(v);
    }
  }    
  cout<<ans<<endl;
  for (ll i = 0; i < answer.size(); ++i)
  {
    cout<<answer[i]<<" ";
  }
  cout<<endl;
  return 0;
}