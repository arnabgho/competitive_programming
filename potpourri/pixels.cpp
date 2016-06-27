#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;

typedef vector<bool> vb;
std::vector<vb> v(1111,(vb(1111)));

bool squareCompleted(int x,int y){
	//bottom right
	if(v[x-1][y-1] && v[x][y-1] && v[x-1][y]) return 1;

	if(v[x+1][y+1] && v[x][y+1] && v[x+1][y]) return 1;

	if(v[x][y-1] && v[x+1][y-1] && v[x+1][y]) return 1;

	if(v[x-1][y] && v[x-1][y+1] && v[x][y+1]) return 1;

	return 0;
}

int main() {
	int n,m,k;
	cin>>n>>m>>k;
	int ans=0;
	for (int i = 1; i <= k; ++i)
	{
		int x,y;
		cin>>x>>y;
		v[x][y]=1;
		if(squareCompleted(x,y) && ans==0){
			ans=i;
		}
	}
	cout<<ans<<endl;
	return 0;
}