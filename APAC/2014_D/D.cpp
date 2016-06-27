#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
#define fi first
#define se second
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
const ll mod=1000000007;
ll powmod(ll a,ll b) {ll res=1;a%=mod;for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
// head



int board[70][70];
int wins[70][70];

map<char,int> St;

int main(){
	St['K']=1;
	St['Q']=2;
	St['R']=3;
	St['B']=4;
	St['N']=5;
	St['P']=6;
	int test;
	cin>>test;
	for (int cas = 1; cas <=test ; ++cas)
	{
		memset(board,0,sizeof(board));
		memset(wins,0,sizeof(wins));
		int n;cin>>n;
		for (int i = 0; i < n; ++i)
		{
			char col,piece;
			int x,y;
			scanf("%c%d-%c",&col,&x,&piece);
			y=col-'A'+1;
			board[x][y]=St[piece];
		}

		

	}
	return 0;	
}
