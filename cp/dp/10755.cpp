#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;

int G[24][24][24];

int main() {
	int t;
	cin>>t;
	while(t--){
		int A,B,C;
		cin>>A>>B>>C;
		memset(G,0,sizeof(G));
		for (int a = 1; a <=A ; ++a)
		{
			for (int b = 1; b <= B ; ++b)
			{
				for (int c = 1; c <=C ; ++c)
				{
					cin>>G[a][b][c];
					G[a][b][c]+=G[a-1][b][c]+G[a][b-1][c]-G[a-1][b-1][c];
				}
			}
		}
		int best=0;
		for (int i = 1; i <=A ; ++i)
		{
			for (int j = 1; j <=B ; ++j)
			{
				for (int k = i;  k<=A ; ++k)
				{
					for (int l = j; l<=B ; ++l)
					{
						int sum=0;
						for (int subrec = 1; subrec <=C ; ++subrec)
						{
							int val=G[k][l][subrec]-G[i-1][l][subrec]-G[k][j-1][subrec]+G[i-1][j-1][subrec];
							sum+=val;
							if(sum<0)
								sum=0;
							best=max(best,sum);
						}
					}
				}
			}
		}
		cout<<best<<endl;
	}
	return 0;
}