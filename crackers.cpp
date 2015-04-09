#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <queue>
#include <algorithm>
#include <string.h>
using namespace std;

int graph[300][300];

long long int parent[400];
bool visited[400];

#define INF 1000000000000

void initialize(long long int n){
	for(long long int i=0;i<n;i++){
		parent[i]=-1;visited[i]=0;
	}
}

bool BFS(long long int n,long long int s,long long int t){
	//cout<<"n: "<<n<<endl;
	initialize(n);
	long long int u,v,p;
	queue<long long int> myQ;
	myQ.push(s);
	visited[s]=1;
	while(!myQ.empty()){
		u=myQ.front();
		myQ.pop();
		p=n;
		for(v=0;v<p;v++){
			//v=adj[u][i]->dest;
			//if(graph[u][v]==0) continue;
			if(!visited[v] && graph[u][v]>0){
				myQ.push(v);
				parent[v]=u;
				visited[v]=1;
			}
		}
	}
	if(!visited[t]) return false;
	else return true;
}

int main(){

	int P,m,pos,i;
	string s,t;
	scanf("%d",&P);
	char a,b,c,d;
	int c_a,c_b,size;
	while(P--){
		s="";
		t="";
		cin>>s;
		cin>>t;
		scanf("%d",&m);
		initialize(26);
		//scanf("%c->%c\n",&a,&b);
		cin>>a>>d>>c>>b;
		//cout<<a<<b;
		c_a=a-97;
		c_b=b-97;
		//cout<<"c_a "<<c_a<<endl;
		//cout<<"c_b "<<c_b<<endl;
		graph[c_a][c_b]=1;
		size=s.size();
		pos=1;
		for(i=0;i<size;i++){
			pos=pos & BFS(26,s[i]-97,t[i]-97);
		}
		if(pos)
			cout<<"YES\n";
		else
			cout<<"NO\n";
	}

	return 0;
}