#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;

typedef pair<int,int> PI;
typedef std::vector<int> VI;

int createTree(int x,std::vector<PI> & parent,std::vector<bool>& visited,std::vector<std::vector<int> >& adj){
			visited[x]=1;int val=1;
			for(int i=0;i<adj[x].size();i++){
				if(!visited[adj[x][i]]){
					parent[adj[x][i]].first=x;
					val+=createTree(adj[x][i],parent,visited,adj);
				}
			}
			parent[x].second=val;
			return val;
}

int main() {
	int a,b,ans,x,i,anc,child,n,t,u,v,maxim,maxpos,root,Q,disco,k;
	char ch;
	cin>>t;
	while(t--){
		cin>>n;
		std::vector<VI> adj(n);
		std::vector<PI> edges;
		pair<int,int> temp;
		for(i=0;i<n-1;i++){
			cin>>u>>v;
			u--;v--;
			adj[u].push_back(v);
			adj[v].push_back(u);
			temp=make_pair(u,v);
			edges.push_back(temp);
		}
		maxim=-1;
		maxpos=-1;
		// for(i=0;i<n;i++){
		// 	cout<<"i :"<<i<<" size "<<adj[i].size()<<endl;
		// }

		for(i=0;i<n;i++){
			k=adj[i].size();
			if(k > maxim){
				maxim=k;
				maxpos=i;
			}
		}
		root=maxpos;
		// cout<<"maxpos "<<maxpos<<endl;
		std::vector<PI> parent(n);
		parent[root].first=-1;
		parent[root].second=n;
		std::vector<bool> visited(n,0);
		// function<int(int)> createTree=[&](int x){
		// 	visited[x]=1;int val=1;
		// 	for(int i=0;i<adj[x].size();i++){
		// 		if(!visited[adj[x][i]]){
		// 			parent[adj[x][i]].first=x;
		// 			val+=createTree(adj[x][i]);
		// 		}
		// 	}
		// 	parent[x].second=val;
		// 	return val;
		// };
		createTree(root,parent,visited,adj);

		// for(i=0;i<n;i++){
		// 	cout<<"i "<<i<<endl;
		// 	cout<<"Parent[i] "<<parent[i].first<<endl;
		// 	cout<<"nodes in subtree "<<parent[i].second<<endl;
		// }

		cin>>Q;
		disco=0;
		while(Q--){
			cin>>ch;
			if(ch=='Q'){
				cout<<disco<<endl;
			}
			else{
				cin>>x;
				u=edges[x-1].first;
				v=edges[x-1].second;
				// cout<<"u "<<u<<" v "<<v<<endl;
				if(parent[u].first==v){
					anc=v;
					child=u;
				}
				else{
					anc=u;
					child=v;
				}
				a=parent[child].second;
				parent[child].first=-1;
				// cout<<"child: "<<child<<endl;
				// cout<<"ancestor: "<<anc<<endl;
				while(parent[anc].first!=-1){
					parent[anc].second-=a;
					anc=parent[anc].first;
					// cout<<"ancestor: "<<anc<<endl;
				}
				// for(i=0;i<n;i++){
				// 	cout<<"i "<<i<<endl;
				// 	cout<<"Parent[i] "<<parent[i].first<<endl;
				// 	cout<<"nodes in subtree "<<parent[i].second<<endl;
				// }
				b=parent[anc].second;
				parent[anc].second-=a;
				// cout<<"a "<<a<<" b "<<b<<endl;				
				disco+=a*(b-a);
			}
		}
	}
	return 0;
}