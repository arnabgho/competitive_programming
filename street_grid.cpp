#include <stdio.h>
#include <queue>
#include <iostream>
#include <stdlib.h>
using namespace std;

struct point{
	int x,y;
};

int reach[21][21];
int horiz[21];
int vert[21];

//0 for right;
//1 for left;
//2 for down;
//3 for up;


queue<struct point*> myQ;

void print_reach(int n,int m){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++)
			cout<<reach[i][j]<<"\t";
		cout<<endl;
	}
}

void reset(){
	for(int i=0;i<21;i++){
		for(int j=0;j<21;j++)
			reach[i][j]=0;
	}
}

void dfs(int x_start,int y_start,int n,int m){
	if(reach[x_start][y_start]>0)
		return ;
	reach[x_start][y_start]=1;
	if(horiz[x_start]==0){
		for(int i=y_start+1;i<=m;i++)
			dfs(x_start,i,n,m);
	}
	else{
		for(int i=y_start-1;i>=1;i--)
			dfs(x_start,i,n,m);
	}

	if(vert[y_start]==2){
		for(int i=x_start+1;i<=n;i++)
			dfs(i,y_start,n,m);
	}
	else{
		for(int i=x_start-1;i>=1;i--)
			dfs(i,y_start,n,m);
	}
}

int allReachable(int x_start,int y_start,int n,int m){
	//struct point* temp;
	//temp=myQ.front();
	//cout<<"temp "<<temp->x;
	dfs(x_start,y_start,n,m);

	int i,j,pos=1;
	for(i=1;i<=n && pos;i++){
		for(j=1;j<=m && pos;j++){
			if(reach[i][j]==0){
				pos=0;
				return 0;
			}
		}
	}
	return pos;
}

int main(){

	int n,m,i,j,pos;
	char ch;
	cin>>n>>m;
	//allReachable(0,0);
	for(i=1;i<=n;i++){
		cin>>ch;
		if(ch=='>')
			horiz[i]=0;
		else
			horiz[i]=1;
	}
	for(i=1;i<=m;i++){
		cin>>ch;
		if(ch=='v')
			vert[i]=2;
		else
			vert[i]=3;
	}
	pos=1;
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			pos=(pos && allReachable(i,j,n,m));
			//print_reach(n,m);
			reset();
		}
	}
	if(pos)
		cout<<"YES\n";
	else
		cout<<"NO\n";
	return 0;
}