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

typedef pair<PII,int> PPI;

int r,c;
int dr[4]={1,0,-1,0};
int dc[4]={0,-1,0,1};
int dp[1010][1010];
bool vis[1010][1010];
std::vector<string> v;
void init(){
	v.clear();
	memset(vis,0,sizeof(vis));
	memset(dp,1e9,sizeof(dp));
}

bool isValid(int i,int j){
	return 0<=i && i<r && 0<=j && j<c && v[i][j]!='#';
}

bool isEdge(int i,int j){
	return isValid(i,j) && (i==0 || j==0 || i==r-1 || j==c-1); 
}

int main(){
	int t;
	cin>>t;
	while(t--){
		init();
		cin>>r>>c;
		string s;
		queue<PII> q;
		PII start;
		for(int i=0;i<r;i++)
			for(int j=0;j<c;j++)
				dp[i][j]=1e9;
			
		for (int i = 0; i < r; ++i)
		{
			string s="";
			cin>>s;
			for (int j = 0; j < c; ++j)
			{
				char ch;
				ch=s[j];
				if(ch=='J')
					start=PII(i,j);
				else if(ch=='F'){
					q.push(PII(i,j));
					dp[i][j]=0;
				}
				
			}
			v.push_back(s);
		}
		// for(auto x:v) cout<<x<<endl;

		
		while(!q.empty()){
			PII p=q.front();q.pop();
			if(dp[p.fi][p.se]!=1e9)
			for (int i = 0; i < 4; ++i)
			{
				if(isValid(p.fi+dr[i],p.se+dc[i]) && dp[p.fi+dr[i]][p.se+dc[i]]==1e9){
					q.push(PII(p.fi+dr[i],p.se+dc[i]));
					dp[p.fi+dr[i]][p.se+dc[i]]=1+dp[p.fi][p.se];
				}
			}
		}
		int ans=1e9;
		bool pos=0;
		queue<PPI> q_J;
		q_J.push(PPI(start,0));
		while(!q_J.empty()){
			PII p=q_J.front().first;
			int tim=q_J.front().second;
			q_J.pop();
			if(vis[p.fi][p.se])
				continue;
			vis[p.fi][p.se]=1;
			if(isEdge(p.fi,p.se)){
				ans=min(ans,tim);
				pos=1;
			}
			for (int i = 0; i <4 ; ++i)
			{
				if(isValid(p.fi+dr[i],p.se+dc[i]) && tim+1<dp[p.fi+dr[i]][p.se+dc[i]] && !vis[p.fi+dr[i]][p.se+dc[i]]){
					q_J.push(  PPI( PII ( p.fi+dr[i],p.se+dc[i]  )  , tim+1 )  );
				}
			}
		}
		if(pos){
			ans++;
			cout<<ans<<endl;
		}
		else
			cout<<"IMPOSSIBLE\n";
	}
	return 0;	
}
