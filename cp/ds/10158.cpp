#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;

typedef std::vector<int> vi;
typedef std::vector<vi> vvi;
class UnionFind{
private: vi p,rank,maxSet;
		int maxim;
public:
	vvi enemies;
	UnionFind(int N){
		maxim=1;
		rank.assign(N,0);p.assign(N,0);maxSet.assign(N,1);
		enemies=vvi(N);
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
				enemies[x].insert(enemies[x].end(),enemies[y].begin(),enemies[y].end());
				enemies[y].clear();
			}	
			else{
				p[x]=y;
				if(rank[x]==rank[y]) rank[y]++;
				maxSet[y]+=maxSet[x];
				maxim=max(maxim,maxSet[y]);
				enemies[y].insert(enemies[y].end(),enemies[x].begin(),enemies[x].end());
				enemies[x].clear();
			}
		}
	}
};


bool areFriends(int x,int y,UnionFind * u){
	return u->isSameSet(x,y);
}

bool areEnemies(int x,int y,UnionFind * u){
	int set_x=u->findSet(x);
	int set_y=u->findSet(y);
	vi enemies_x=u->enemies[set_x];
	vi enemies_y=u->enemies[set_y];
	for (int i = 0; i < enemies_x.size(); ++i)
	{
		if(enemies_x[i]==y) return 1;
	}
	for (int i = 0; i < enemies_y.size(); ++i)
	{
		if(enemies_y[i]==x) return 1;
	}

	return 0;
}

int setFriends(int x,int y,UnionFind * u){
	if(areEnemies(x,y,u)) return -1;
	u->unionSet(x,y);
	return -2;
}

int setEnemies(int x,int y,UnionFind * u){
	if(areFriends(x,y,u)) return -1;
	int set_x=u->findSet(x);
	int set_y=u->findSet(y);
	u->enemies[set_x].push_back(y);
	u->enemies[set_y].push_back(x);
	vi enemies_x=u->enemies[set_x];
	vi enemies_y=u->enemies[set_y];
	for (auto i:enemies_x)
	{
		u->unionSet(i,y);
	}
	for (auto i:enemies_y)
	{
		u->unionSet(i,x);
	}
	return -2;
}

int main() {
	int n;
	cin>>n;
	UnionFind * u=new UnionFind(n);
	int q,x,y;
	cin>>q>>x>>y;
	// int temp=0;
	while(q+x+y>0 ){
		// cout<<"q "<<q<<" x "<<x<<" y "<<y<<endl;
		int res=-2;
		// temp++;
		if(q==1) res=setFriends(x,y,u);
		else if(q==2) res=setEnemies(x,y,u);
		else if(q==3) res=areFriends(x,y,u);
		else if(q==4) res=areEnemies(x,y,u);
		if(res!=-2)
			cout<<res<<endl;
		cin>>q>>x>>y;
	}
	return 0;
}