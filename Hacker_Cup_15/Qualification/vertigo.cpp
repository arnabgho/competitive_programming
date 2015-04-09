#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;
const int inf=1e8;
std::vector<string> v;
int minTurns[200][200];
int visited[200][200]={{false}};
typedef pair<int,int> pi;
typedef pair<pi,int> ppi;
int r,c;
bool isValid(int i,int j){
	return (0<=i && i<r && 0<=j && j<c);
}

int main() {
	int si,sj,ei,ej;
	cin>>r>>c;
	string s;
	for (int i = 0; i <r ; ++i)
	{
		cin>>s;
		v.push_back(s);
	}
	for (int i = 0; i < r; ++i)
	{
		for (int j = 0; j < c; ++i)
		{
			if(v[i][j]=='#')
				minTurns[i][j]=-1;
			else
				minTurns[i][j]=1e8;
			if(v[i][j]=='S'){
				si=i;sj=j;
			}
			if(v[i][j]=='E'){
				ei=i;ej=j;
			}
		}
	}
	queue<ppi> myQ;
	visited[si][sj]=1;
	myQ.push(make_pair(make_pair(si,sj),0));
	while(!myQ.empty()){
		pi u=myQ.front().first;
		int x,y;
		x=u.first;
		y=u.second;
		if(x==ei && y==ej){
			ans=myQ.front().second;
			break;
		}
		if(isValid(x+1,y+1)){
			visited[x+1][y+1]=true;
			myQ.push(make_pair(x+1,y+1),);
		}
		if(isValid(x-1,y+1)){
			visited[x-11][y+1]=true;
			myQ.push(make_pair(x-1,y+1),);
		}
		if(isValid(x+1,y-1)){
			visited[x+1][y-1]=true;
			myQ.push(make_pair(x+1,y-1),);
		}
		if(isValid(x-1,y-1)){
			visited[x-1][y-1]=true;
			myQ.push(make_pair(x-1,y-1),);
		}
	}
	return 0;
}