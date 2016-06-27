#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;
typedef pair<int,int> pi;
int N,M;
set<int> G[10];
void init(){
	for (int i = 0; i < 10; ++i)
	{
		G[i].clear();
	}
}

bool compareVal(string s1,string s2){
	for (int i = 0; i < s1.size(); ++i)
	{
		if(s1[i]==s2[i]) continue;
		return (s1[i]<s2[i]);
	}
	return 1;
}

bool isValid(std::vector<int> perm){
	if(perm.size()==1) return 1;
	stack<int> S;
	std::vector<bool> visited(N,0);
	map<pi,int> E;
	int start=perm[0];
	int cur=perm[1];
	if(G[start].find(cur)==G[start].end()) return 0;
	if(perm.size()<3) return 1;
	S.push(start);	
	S.push(cur);
	visited[start]=1;visited[cur]=1;
	E[pi(start,cur)]=1;
	int i=2;
	// cout<<"Permuation : \n";
	// for (int i = 0; i < perm.size(); ++i)
	// {
	// 	cout<<perm[i]<<" ";
	// }
	// cout<<"------\n";
	while(i<perm.size()){
		int t=S.top();
		cur=perm[i];
		// cout<<"top "<<t<<endl;
		// cout<<"cur "<<cur<<endl;
		if(G[t].find(cur)!=G[t].end()){
			i++;
			visited[cur]=1;
			S.push(cur);
		}
		else{
			S.pop();
			if(S.size()==0) return 0;
		}
	}
	bool pos=1;
	for (int i = 0; i < N; ++i)
	{
		if(!visited[i]) return 0;
	}
	return 1;
}

int main() {
	int T;
	cin>>T;
	for (int cas = 1; cas <=T ; ++cas)
	{
		init();
		cin>>N>>M;
		std::vector<string> v;
		std::vector<int> perm;
		for (int i = 0; i < N; ++i)
		{
			string s;
			cin>>s;
			v.push_back(s);
			perm.push_back(i);
		}
		for (int i = 0; i < M; ++i)
		{
			int u,v;
			cin>>u>>v;
			u--;v--;
			G[u].insert(v);
			G[v].insert(u);
		}
		string mn="";
		do{
			if(!isValid(perm)) continue;
			string s="";
			for (int i = 0; i < perm.size(); ++i) s+=v[perm[i]];
			if( mn=="" || compareVal(s,mn) )
				mn=s;	
		}while(next_permutation(perm.begin(),perm.end()));
		cout<<"Case #"<<cas<<": "<<mn<<endl;
	}

	return 0;
}