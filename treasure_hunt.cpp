#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;
std::vector<int> Tr(31001,0);
int maxtr;
typedef pair<int,int> pi;
map<pi,int> DP;
int dfs(int p,int c){
	int l=c-p;
	pi pr=make_pair(p,c);
	if(DP.find(pr)!= DP.end())
		return DP[pr];

	if(c<=p || c>=maxtr+l)
		return 0;
	int maxim=0;
	if(l-1>0 && c+l-1<=maxtr+l){
		maxim=max(dfs(c,c+l-1),maxim);
		// cout<<" maxim "<<maxim<<endl;
	}
	if(l>0 && c+l<=maxtr+l){
		maxim=max(dfs(c,c+l),maxim);
		// cout<<" maxim "<<maxim<<endl;
	}
	if(l+1>0 && c+l+1<=maxtr+l){
		maxim=max(dfs(c,c+l+1),maxim);
		// cout<<" maxim "<<maxim<<endl;
	}
	// cout<<"p "<<p <<" c "<<c<<endl;
	// cout<<"Trc "<<Tr[c]<<endl;
	maxim+=Tr[c];
	DP[pr]=maxim;
	return maxim;
}

int main() {
	int n,d;
	cin>>n>>d;
	for (int i = 0; i <n ; ++i)
	{
		int p;
		cin>>p;
		Tr[p]+=1;
		maxtr=max(maxtr,p);
	}
	// maxtr=30000;
	// cout<<"maxtr "<<maxtr<<endl;
	int ans=dfs(0,d);
	cout<<ans<<endl;
	return 0;
}