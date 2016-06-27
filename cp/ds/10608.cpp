#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;

typedef std::vector<int> vi;
class UnionFind{
private: vi p,rank,maxSet;
		int maxim;
public:
	UnionFind(int N){
		maxim=1;
		rank.assign(N,0);p.assign(N,0);maxSet.assign(N,1);
		for (int i = 0; i < N; ++i) p[i]=i;
	}
	int getMaxim(){return maxim;}
	int findSet(int i){ return (p[i]==i) ? i:p[i]=findSet(p[i]); }
	bool isSameSet(int i,int j){return findSet(i)==findSet(j);}
	void unionSet(int i,int j){
		if(!isSameSet(i,j)){
			int x=findSet(i);int y=findSet(j);
			if(rank[x]>rank[y]){ 
				p[y]=x;
				maxSet[x]+=maxSet[y];
				maxim=max(maxim,maxSet[x]);
			}	
			else{
				p[x]=y;
				if(rank[x]==rank[y]) rank[y]++;
				maxSet[y]+=maxSet[x];
				maxim=max(maxim,maxSet[y]);
			}
		}
	}
};



int main() {
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		UnionFind * u=new UnionFind(n);
		for (int i = 0; i < m; ++i)
		{
			int a,b;
			cin>>a>>b;
			a--;b--;
			if(!u->isSameSet(a,b))
				u->unionSet(a,b);
		}
		cout<<u->getMaxim()<<endl;
		delete(u);
	}
	return 0;
}