#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;
typedef long long ll;
typedef pair<ll,ll> PL;
const double eps=1e-9;

typedef std::vector<string> VS;
VS v;
VS dest;

map<VS,ll> DP;
map<VS,bool> check_dest;

ll n;

bool isValid(int i,int j){
	return 0<=i && i<n && 0<=j && j<n;
}
int dx[8]={1,1,0,-1,-1,-1,0,1};
int dy[8]={0,1,1,1,0,-1,-1,-1};

VS closure(VS cur,ll x,ll y){
	if(dest[x][y]!='0'){
		cur[x][y]=dest[x][y];
		return cur;
	}
	queue<PL> q;
	map<PL,bool> vis;
	q.push(PL(x,y));
	while(!q.empty()){
		PL p=q.front();
		q.pop();
		if(vis.count(p))
			continue;
		vis[p]=1;
		cur[p.first][p.second]='0';
		for (int i = 0; i < 8; ++i)
		{
			if(isValid(p.first+dx[i],p.second+dy[i])){
				if(cur[p.first+dx[i]][p.second+dy[i]]!='*'){
					cur[p.first+dx[i]][p.second+dy[i]]=dest[p.first+dx[i]][p.second+dy[i]];
					if(cur[p.first+dx[i]][p.second+dy[i]]=='0')
						q.push(PL(p.first+dx[i],p.second+dy[i]));
				}
			}	
		}
	}
	return cur;
}

ll recurse(VS cur){
	if(check_dest.count(cur))
		return 0;
	if(DP.count(cur))
		return DP[cur];
	ll ans=1e9;
	std::vector<PL> zeros;
	int num=0;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j <n; ++j)
		{
			if(cur[i][j]=='.' && dest[i][j]=='0'){
				zeros.push_back(PL(i,j));
			}
			if(cur[i][j]=='.') num++;
		}
	}
	if(zeros.size()){
		for(auto p:zeros){
			VS temp=closure(cur,p.first,p.second);
			ans=min(ans,1+recurse(temp));
		}
	}
	else ans=num;
	return DP[cur]=ans;
}

void init(){
	v.clear();
	DP.clear();
	dest.clear();
	check_dest.clear();
}
int main() {
	ll t;
	cin>>t;
	for (ll cas = 1; cas <= t; ++cas)
	{
		/* code */
		init();
		cin>>n;
		for (int i = 0; i < n; ++i)
		{
			string s;
			cin>>s;
			v.push_back(s);
		}
		dest=v;
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				if(dest[i][j]=='*') continue;	
				int count=0;
				for (int k = 0; k < 8; ++k)
				{
					if(isValid(i+dx[k],j+dy[k]) && v[i+dx[k]][j+dy[k]]=='*')
						count++;
				}
				dest[i][j]='0'+count;
			}
		}

		check_dest[dest]=1;
		VS cur=v;
		ll ans=0;
		while(check_dest.count(cur)==0){
			// for(auto s:cur)
			// 	cout<<s<<endl;
			// cout<<"\n-------------------------\n";
			std::vector<PL> zeros;
			int num=0;
			for (int i = 0; i < n; ++i)
			{
				for (int j = 0; j <n; ++j)
				{
					if(cur[i][j]=='.' && dest[i][j]=='0'){
						zeros.push_back(PL(i,j));
					}
					if(cur[i][j]=='.') num++;
				}
			}
			if(!zeros.size()){
				ans+=num;break;
			}
			cur=closure(cur,zeros[0].first,zeros[0].second);
			ans++;
		}

		// ll ans=recurse(v);
		printf("Case #%lld: %lld\n",cas,ans);
	}
	return 0;
}