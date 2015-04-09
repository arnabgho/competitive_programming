bool isCycle;

void Cycledfs(int u){
	//cout<<"u "<<u<<endl;
	if(visited[u]==2)
		return ;
	if(visited[u]==1){
		isCycle=1;
		return;
	}		
	visited[u]=1;
	for(int v=0;v<G[u].size();v++){
		if(redG[u][v]=='1')
			Cycledfs(v);
	}
	visited[u]=2;
}