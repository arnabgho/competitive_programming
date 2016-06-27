#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;
typedef std::vector<int> vi;

std::vector<vi> G(1111);
int N;
void init(){
	for (int i = 0; i < 1111; ++i)
		G[i].clear();
}
typedef pair<int,int> pi;
std::vector<int> sub(1111,-1);
int maxRem(int u,int p){
	if(sub[u]!=-1)
		return sub[u];
	std::vector<pi> vec;
	for (int i = 0; i < G[u].size(); ++i)
	{
		int v=G[u][i];
		if(v==p) continue;
		vec.push_back(pi(maxRem(v,u),v));
	}
	sort(vec.rbegin(),vec.rend());
	if(vec.size()<2)
		sub[u]=1;
	else
		sub[u]=vec[0].first+vec[1].first+1;
	return sub[u];
}

int main() {
	int T;
	cin>>T;
	for (int cas = 1; cas <=T ; ++cas)
	{
		init();
		cin>>N;
		for (int i = 1; i < N; ++i)
		{
			int x,y;
			cin>>x>>y;
			G[x].push_back(y);
			G[y].push_back(x);
		}
		int mx=0;
		for(int i=1;i<=N;i++){
			fill(sub.begin(),sub.end(),-1);
			mx=max(mx,maxRem(i,-1));
		}	
		cout<<"Case #"<<cas<<": "<<N-mx<<endl;
	}
	return 0;
}