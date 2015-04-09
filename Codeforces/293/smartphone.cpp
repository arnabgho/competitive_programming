#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;

std::map<int, int> pos;
std::vector<int> screen;
int main() {
	int n,m,k;
	cin>>n>>m>>k;
	for (int i = 0; i < n; ++i)
	{
		int a;
		cin>>a;
		screen.push_back(a);
		pos[a]=i;
	}
	long long int ans=0;
	for (int i = 0; i < m; ++i)
	{
		int b;
		cin>>b;
		int p=pos[b];
		if(p==0)
			ans++;
		else{
			int n=p/k+1;
			ans+=n;
			swap(screen[p],screen[p-1]);
			pos[screen[p]]=p;
			pos[screen[p-1]]=p-1;
		}
	}
	cout<<ans<<endl;
	return 0;
}