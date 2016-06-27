#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;

typedef std::vector<int> vi;
class UnionFind{
private: vi p,rank;
public:
	UnionFind(int N){
		rank.assign(N,0);p.assign(N,0);
		for (int i = 0; i < N; ++i) p[i]=i;
	}
	
	int findSet(int i){ return (p[i]==i) ? i:p[i]=findSet(p[i]); }
	bool isSameSet(int i,int j){return findSet(i)==findSet(j);}
	void unionSet(int i,int j){
		if(!isSameSet(i,j)){
			int x=findSet(i);int y=findSet(j);
			if(rank[x]>rank[y]) p[y]=x;
			else{
				p[x]=y;
				if(rank[x]==rank[y]) rank[y]++;
			}
		}
	}
};

int main() {
	int n,m;
	cin>>n>>m;
	while(n+m>0){
		UnionFind * u=new UnionFind(n);
		for (int i = 0; i < m; ++i)
		{
			int k,a;
			cin>>k>>a;
			for (int j = 1; j < k; ++j)
			{
				int b;
				cin>>b;
				u->unionSet(a,b);
			}
		}
		int count=1;
		for (int i = 1; i <n ; ++i)
		{
			count+=u->isSameSet(i,0);
		}
		cout<<count<<endl;
		delete(u);
		cin>>n>>m;
	}
	return 0;
}