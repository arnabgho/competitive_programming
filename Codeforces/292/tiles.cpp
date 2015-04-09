#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;
typedef pair<int,int> pi;

std::vector<string> grid;
int n,m;
bool isValid(int i,int j){
	return (0<=i && i<n && 0<=j && j<m);
}


int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};

bool checkDeg(int i,int j){
	int c=0;
	for (int k = 0; k < 4; ++k)
	{
		if(isValid(i+dx[k],j+dy[k]) && grid[i+dx[k]][j+dy[k]]=='.')/* code */
			c++;
	}
	return (c==1);
}


int main() {
	
	cin>>n>>m;
	for (int i = 0; i < n; ++i)
	{
		string s;
		cin>>s;
		grid.push_back(s);
	}
	queue<pi> d;
	int nfilled=0;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if(grid[i][j]=='*'){
				nfilled++;
			 	continue;
			}
			int c=0;
			for (int k = 0; k < 4; ++k)
			{
				if(isValid(i+dx[k],j+dy[k]) && grid[i+dx[k]][j+dy[k]]=='.')/* code */
					c++;
			}
			if(c==1)
				d.push(make_pair(i,j));
		}
	}
	//deal only with . 
	while(!d.empty()){
		pi p=d.front();
		d.pop();
		int i=p.first;
		int j=p.second;
		if(grid[i][j]!='.') continue;
		if(isValid(i-1,j) && grid[i-1][j]=='.'){
			grid[i-1][j]='^';
			grid[i][j]='v';
			nfilled+=2;	
			for (int k = 0; k < 4; ++k)
			{
				if(isValid(i+dx[k],j+dy[k]) && grid[i+dx[k]][j+dy[k]]=='.'){/* code */
					if(checkDeg(i+dx[k],j+dy[k]))
						d.push(make_pair(i+dx[k],j+dy[k]));
				}	
			}

			i=i-1;
			
			for (int k = 0; k < 4; ++k)
			{
				if(isValid(i+dx[k],j+dy[k]) && grid[i+dx[k]][j+dy[k]]=='.'){/* code */
					if(checkDeg(i+dx[k],j+dy[k]))
						d.push(make_pair(i+dx[k],j+dy[k]));
				}	
			}

			continue;
		}
		else if(isValid(i+1,j) && grid[i+1][j]=='.'){
			grid[i][j]='^';
			grid[i+1][j]='v';
			nfilled+=2;

			for (int k = 0; k < 4; ++k)
			{
				if(isValid(i+dx[k],j+dy[k]) && grid[i+dx[k]][j+dy[k]]=='.'){/* code */
					if(checkDeg(i+dx[k],j+dy[k]))
						d.push(make_pair(i+dx[k],j+dy[k]));
				}	
			}

			i=i+1;	

			for (int k = 0; k < 4; ++k)
			{
				if(isValid(i+dx[k],j+dy[k]) && grid[i+dx[k]][j+dy[k]]=='.'){/* code */
					if(checkDeg(i+dx[k],j+dy[k]))
						d.push(make_pair(i+dx[k],j+dy[k]));
				}	
			}
			
			continue;
		}
		else if(isValid(i,j+1) && grid[i][j+1]=='.'){
			grid[i][j]='<';
			grid[i][j+1]='>';
			nfilled+=2;

			for (int k = 0; k < 4; ++k)
			{
				if(isValid(i+dx[k],j+dy[k]) && grid[i+dx[k]][j+dy[k]]=='.'){/* code */
					if(checkDeg(i+dx[k],j+dy[k]))
						d.push(make_pair(i+dx[k],j+dy[k]));
				}	
			}

			j=j+1;
			
			for (int k = 0; k < 4; ++k)
			{
				if(isValid(i+dx[k],j+dy[k]) && grid[i+dx[k]][j+dy[k]]=='.'){/* code */
					if(checkDeg(i+dx[k],j+dy[k]))
						d.push(make_pair(i+dx[k],j+dy[k]));
				}	
			}

			continue;
		}
		else if(isValid(i,j-1) && grid[i][j-1]=='.'){
			grid[i][j]='>';
			grid[i][j-1]='<';
			nfilled+=2;
			for (int k = 0; k < 4; ++k)
			{
				if(isValid(i+dx[k],j+dy[k]) && grid[i+dx[k]][j+dy[k]]=='.'){/* code */
					if(checkDeg(i+dx[k],j+dy[k]))
						d.push(make_pair(i+dx[k],j+dy[k]));
				}	
			}

			j=j-1;
			
			for (int k = 0; k < 4; ++k)
			{
				if(isValid(i+dx[k],j+dy[k]) && grid[i+dx[k]][j+dy[k]]=='.'){/* code */
					if(checkDeg(i+dx[k],j+dy[k]))
						d.push(make_pair(i+dx[k],j+dy[k]));
				}	
			}
			continue;
		}
	}

	if(nfilled==m*n){
		for (int i = 0; i < n; ++i)
		{
			cout<<grid[i]<<endl;/* code */
		}
	}
	else
		cout<<"Not unique\n";
	return 0;
}