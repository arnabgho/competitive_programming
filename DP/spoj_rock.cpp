#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;
std::vector<int> A;
int DP[500];
int isValid[500][500];
int cum[500];
//DP[i][j] represents the best possible length from A[i]...A[j]
int main() {
	int t;
	cin>>t;
	while(t--){
		
		int n,x,sum=0;
		cin>>n;
		A.push_back(0);
		string s;
		cin>>s;
		for (int i = 1; i <= n; ++i)
		{
			x=s[i-1]-'0';
			A.push_back(x);
		}
		for (int i = 1; i <= n; ++i)
		{
			sum+=A[i];
			cum[i]=sum;
		}
		for (int i = 1; i <= n; ++i)
		{
			for (int j = i; j <=n ; ++j)
			{
				int segSum=cum[j]-cum[i-1];
				int segL=j-i+1;
				int numZ=segL-segSum;
				if(numZ<segSum)
					isValid[i][j]=1;
			}
		}

		int ans=A[1];
		DP[1]=A[1];
		for (int i = 2; i <=n ; ++i)
		{
			int maxim=0;
			for (int j = i; j >=1 ; --j)
			{
				if(!isValid[j][i])
					continue;
				int segL=i-j+1;
				for (int k = 0; k <=j-1 ; ++k)
				{
					maxim=max(DP[k]+segL,maxim);
				}
			}
			DP[i]=maxim;
			ans=max(DP[i],ans);
		}
		cout<<ans<<endl;
		A.clear();
		memset(DP,0,sizeof(DP));
		memset(cum,0,sizeof(cum));
		memset(isValid,0,sizeof(isValid));
	}	
	return 0;
}