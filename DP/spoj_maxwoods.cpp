#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define INF 1e9
using namespace std;
typedef vector<int> vi;
int dp[300][300][2];
std::vector<vi> state(300,vi(300,0));
int n,m;
bool isValid(int i,int j){
	return (0<=i && i<n) && (0<=j && j<m) && (state[i][j]!=-1);
}
//0 represents right 1 represents left
int main() {
	int t;
	cin>>t;
	while(t--){
		cin>>m>>n;
		for (int i = 0; i < n; ++i)
		{
			string s;
			cin>>s;
			for (int j = 0; j < m; ++j)
			{
				dp[i][j][0]=-INF;
				dp[i][j][1]=-INF;
				if(s[j]=='T')
					state[i][j]=1;
				if (s[j]=='#')
					state[i][j]=-1;
				if (s[j]=='0')
					state[i][j]=0;
			}
		}
		if(state[0][0]==-1){
			cout<<0<<endl;
			continue;
		}
		dp[0][0][0]=state[0][0];
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				if(state[i][j]==-1){
					dp[i][j][0]=-INF;
					dp[i][j][1]=-INF;
				}
				else {
					//facing right
					if(isValid(i,j+1)){
						dp[i][j+1][0]=max(dp[i][j+1][0],dp[i][j][0]+state[i][j+1]);
					}
					if(isValid(i+1,j)){
						dp[i+1][j][1]=max(dp[i+1][j][1],dp[i][j][0]+state[i+1][j]);
						dp[i+1][j][0]=max(dp[i+1][j][0],dp[i][j][1]+state[i+1][j]);
					}
					//facing left
					if(isValid(i,j-1)){
						dp[i][j-1][1]=max(dp[i][j-1][1],dp[i][j][1]+state[i][j-1]);
					}
				}
				
			}
			for (int j = m-1; j >=0 ; --j)
			{
				if(state[i][j]==-1){
					dp[i][j][0]=-INF;
					dp[i][j][1]=-INF;
				}
				else {
					//facing right
					if(isValid(i,j+1)){
						dp[i][j+1][0]=max(dp[i][j+1][0],dp[i][j][0]+state[i][j+1]);
					}
					if(isValid(i+1,j)){
						dp[i+1][j][1]=max(dp[i+1][j][1],dp[i][j][0]+state[i+1][j]);
						dp[i+1][j][0]=max(dp[i+1][j][0],dp[i][j][1]+state[i+1][j]);
					}
					//facing left
					if(isValid(i,j-1)){
						dp[i][j-1][1]=max(dp[i][j-1][1],dp[i][j][1]+state[i][j-1]);
					}
				}
				
			}
		}
		int maxim=-INF;
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				if(state[i][j]!=-1)
					maxim=max(maxim,max(dp[i][j][0],dp[i][j][1]));
			}
		}
		if(maxim==-INF)
			cout<<0<<endl;
		else
			cout<<maxim<<endl;
	}
	return 0;
}