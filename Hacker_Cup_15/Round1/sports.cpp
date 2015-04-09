#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;
typedef long long ll;
const ll inf=1e9;
const ll MOD=1e9+7;
typedef std::vector<ll> vl;
int main() {
	int t;
	cin>>t;
	for (int cas = 1; cas <=t ; ++cas)
	{
		int a,b;
		std::vector<vl> sfr(2222,vl(2222,-inf));
		std::vector<vl> sfu(2222,vl(2222,-inf));
		sfr[1][0]=1;
		scanf("%d-%d",&a,&b);
		for (int i = 1; i <=a ; ++i)
		{
			sfr[i][0]=1;
		}
		for (int j = 1; j <=b ; ++j)
		{
			for (int i = j+1; i <=a ; ++i)
			{
				if(i-1>j){
					sfr[i][j]=(sfr[i-1][j]+sfr[i][j-1])%MOD;
				}
				else{
					sfr[i][j]=sfr[i][j-1];
				}
			}
		}

		for (int i = 0; i <=b ; ++i)
		{
			sfu[i][0]=1;
		}
		for (int j = 1; j <=b ; ++j)
		{
			for (int i = j; i <=b ; ++i)
			{
				if(i-1>=j){
					sfu[i][j]=(sfu[i-1][j]+sfu[i][j-1])%MOD;
				}
				else{
					sfu[i][j]=sfu[i][j-1];
				}

			}
		}


		cout<<"Case #"<<cas<<": "<<sfr[a][b]<<" "<<sfu[b][b]<<endl;
	}
	return 0;
}