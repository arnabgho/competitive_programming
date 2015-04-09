#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <cstring>
#include <vector>
using namespace std;
const int inf=1e6;
int w,h;
std::vector<string> city(200);
int dp[200][200][200];

int cell(int x,int y){
	x--;y--;
	if(city[x][y]=='#')
		return -inf;
	return city[x][y]=='*' ? 1:0; 
}

int main() {
	int t;
	cin>>t;
	while(t--){
		int w,h;
		cin>>w>>h;
		for (int i = 0; i < h; ++i)
		{
			cin>>city[i];
		}
		memset(dp,0,sizeof dp);
		cout<<"dp[0][0] "<<dp[0][0]<<endl;
		for (int i = 1; i <=h ; ++i)
		{
			for (int j = 1; j <=w; ++j)
			{
				if(cell(i,j)== -inf)
					continue;
				int sum=i+j;
				int limit=min(sum,100);
				for (int k = i; k <=limit ; ++k)
				{
					dp[i][j][k]=max(max(dp[i-1][j][k],dp[i][j-1][k]),max(dp[i-1][j][k-1],dp[i][j-1][k-1]))+cell(i,j);
					if(k!=i)
						dp[i][j][k]+=cell(k,sum-k);
				}
			}
		}
		cout<<dp[h][w][h]<<endl;
	}
	return 0;
}