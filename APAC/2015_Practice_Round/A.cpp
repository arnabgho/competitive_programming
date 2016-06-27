#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;

typedef std::vector<int> vi;

std::vector<vi> G(1000);
map<string,int> L;
int vis[1000];
void init(){
	L.clear();
	memset(vis,-1,sizeof(vis));
	for (int i = 0; i <1000 ; ++i)
	{
		G[i].clear();
	}
}

int main() {
	int t;
	cin>>t;
	for (int cas = 1; cas <=t ; ++cas)
	{
		init();
		int m,p=1;
		cin>>m;
		for (int i = 0; i < m; ++i)
		{
			string s1,s2;
			cin>>s1>>s2;
			if(!L.count(s1))
				L[s1]=p++;
			if(!L.count(s2))
				L[s2]=p++;
			G[L[s1]].push_back(L[s2]);
			G[L[s2]].push_back(L[s1]);
		}
		queue<int> Q;
		bool pos=1;
		Q.push(1);
		vis[1]=0;
		while(!Q.empty() && pos){
			int cur=Q.front();
			int state=vis[cur];
			Q.pop();
			for (auto v:G[cur])
			{
				if(vis[v]==state)
					pos=0;
				else if(vis[v]==-1){
					vis[v]=(state+1)%2;
					Q.push(v);
				}
			}
		}
		if(pos)
			printf("Case #%d: Yes\n",cas );
		else
			printf("Case #%d: No\n",cas );			
	}
	return 0;
}