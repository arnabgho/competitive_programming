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
typedef pair<double,double> PII;
const ll mod=1000000007;
ll powmod(ll a,ll b) {ll res=1;a%=mod;for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
// head

std::vector<std::string> tokenizer( const std::string& p_pcstStr, char delim )  {
        std::vector<std::string> tokens;
        std::stringstream   mySstream( p_pcstStr );
        std::string         temp;

        while( getline( mySstream, temp, delim ) ) {
            tokens.push_back( temp );
        }

        return tokens;
    } 

typedef pair<int,double> PID;
std::vector<PII> P;
int G[1000][1000];
double getDist(PII u,PII v){
	// cout<<"return "<<sqrt( (u.fi-v.fi)*(u.fi-u.fi)+(u.se-v.se)*(u.se-v.se))<<endl;
	return sqrt( (u.fi-v.fi)*(u.fi-v.fi)+(u.se-v.se)*(u.se-v.se)) ;
}



int main(){
	int test;
	scanf("%d",&test);
	while(test--){
		PII st,t;
		scanf("%lf %lf %lf %lf",&st.fi,&st.se,&t.fi,&t.se);
		cin.ignore(100, '\n');
		string s;
		int n=0;
		memset(G,0,sizeof(G));
		P.clear();
		while(getline(cin,s)){
			if(!s.size()) break;
			std::vector<string> parsed=tokenizer(s,' ');
			for(int i=0;i<parsed.size();i+=2){
				double u=stod(parsed[i]);double v=stod(parsed[i+1]);
				if(u+v!=-2) {
					P.push_back(PII(u,v));
					if(i!=0){
						G[n][n-1]=getDist(P[n],P[n-1]);
						G[n-1][n]=G[n][n-1];
					}
					n++;
				} 	
			}
		}
		P.push_back(st);
		P.push_back(t);
		n+=2;
		for (int i = 0; i < n; ++i)
		{
			for (int j = i+1; j < n; ++j)
			{
				if(G[i][j]==0){
					G[i][j]=4*getDist(P[i],P[j]);
					G[j][i]=G[i][j];
				}	
			}
		}

		for (int k = 0; k < n; ++k)
		{
			for (int i = 0; i < n; ++i)
			{
				for (int j = 0; j < n; ++j)
				{
					if(i==j) continue;
					G[i][j]=min(G[i][j],G[i][k]+G[k][j]);
				}
			}
		}


		int ans=G[n-1][n-2]*0.0015+0.5;
		cout<<ans<<endl;
		
	}

	return 0;	
}
