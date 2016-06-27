#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;

bool Grid[600][600];
int RowBest[600];
int longestStreak(int row){
	int ans=0;
	int cur=0;
	for (int j = 1; j <=600 ; ++j)
	{
		if(Grid[row][j]==0){
			ans=max(ans,cur);
			cur=0;
		}
		else{
			cur++;
		}
	}
	return ans;
}

int main() {
	int n,m,q;
	cin>>n>>m>>q;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m ; ++j)
		{
			cin>>Grid[i][j];
		}
	}
	for (int i = 1; i <=n ; ++i)
	{
		RowBest[i]=longestStreak(i);
	}
	for (int i = 0; i < q; ++i)
	{
		int x,y;
		cin>>x>>y;
		Grid[x][y]=!Grid[x][y];
		RowBest[x]=longestStreak(x);
		int mx=0;
		for (int j = 1; j <=n ; ++j)
		{
			mx=max(mx,RowBest[j]);
		}
		cout<<mx<<endl;
	}
	return 0;
}