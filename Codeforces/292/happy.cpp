#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;
std::vector<bool> b(200,0);
std::vector<bool> g(200,0);
int main() {
	int n,m,hb=0,hg=0;
	cin>>n>>m;
	cin>>hb;
	for (int i = 0; i < hb; ++i)
	{
		int x;
		cin>>x;
		b[x]=1;
	}
	cin>>hg;
	for (int i = 0; i <hg ; ++i)
	{
		int x;
		cin>>x;
		g[x]=1;
	}

	for (int i = 0; i <100*n*m ; ++i)
	{
		int xb=i%n;
		int xg=i%m;
		if((b[xb]+g[xg])==1){
			if(b[xb]==1){
				g[xg]=1;
				hg++;
			}
			else{
				b[xb]=1;
				hb++;
			}
		}
	}
	if(hb==n && hg==m)
		cout<<"Yes\n";
	else
		cout<<"No\n";
	return 0;
}