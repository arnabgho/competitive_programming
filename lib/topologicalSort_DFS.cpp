stack<int> revtop;
void topological(int u){
	if(visited[u])
		return ;
	visited[u]=1;
	for(int v=0;v<redG.size();v++)
		if(redG[u][v]=='1') topological(v);
	revtop.push(u);			
}
