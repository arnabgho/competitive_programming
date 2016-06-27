#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;
int C[100][100][4];
int m[100];
int t1,t2,n;
typedef std::vector<int> vi;
typedef pair<int,vi> pv;
typedef pair<int,int> pi;
typedef pair<int, pi > pip;
map<pip,pv> DP;

std::vector<int> empty;

pv recurse(int id,int rem1,int rem2){
	if(rem1<0 || rem2<0)
		return pv(1e9,empty);
	if(id==n ){
		if(rem1==0 && rem2==0)
			return pv(0,empty);
		else
			return pv(1e9,empty);
	}
	pip cur=pip(id,pi(rem1,rem2));
	if(DP.count(cur))
		return DP[cur];
	int minim=2e9;
	std::vector<int> min_vec=empty;
	for (int x = 0; x <=m[id] ; ++x)
	{
		pv p;
		if(rem1>=x && rem2>=m[id]-x){
			p=recurse(id+1,rem1-x,rem2-m[id]+x);
			if(p.first+ C[id][x][1] +C[id][m[id]-x][2] <minim){
				minim=p.first+ C[id][x][1] +C[id][m[id]-x][2];
				p.second.push_back(x);
				min_vec=p.second;
			}
		}
	}
	return DP[cur]=pv(minim,min_vec);
}

int main() {
	cin>>t1>>t2;
	while(t1+t2>0){
		cin>>n;
		memset(C,0,sizeof(C));
		memset(m,0,sizeof(m));
		DP.clear();
		for (int i = 0; i < n; ++i)
		{
			cin>>m[i];
			for (int k = 1; k<=2 ; ++k)
			{
				for (int j = 1; j <=m[i] ; ++j)
				{
					cin>>C[i][j][k];
				}
			}
		}
		pv ans=recurse(0,t1,t2);
		cout<<ans.first<<endl;
		reverse(ans.second.begin(),ans.second.end());
		for(auto x:ans.second)
			cout<<x<<" ";
		cout<<endl;
		cin>>t1>>t2;
	}
	return 0;
}