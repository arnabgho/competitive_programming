#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;
typedef pair<int,int> pi;
std::vector<pi> v;
std::vector<std::vector<int> > G(1000);
map<pi,int> DP;
int main() {
	int k;
	cin>>k;
	if(k%2==0){cout<<"NO\n";return 0;}
	int n=4*k-2;
	for (int i = 2; i <= k ; ++i)
	{
		G[1].push_back(i);
		G[i].push_back(1);
		for (int j = k+1 ; j <=2*k-1 ; ++j)
		{
			G[j].push_back(i);
			G[i].push_back(j);
		}
	}
	for (int i = k+1; i <=2*k-1 ; i+=2)
	{
		G[i].push_back(i+1);
		G[i+1].push_back(i);
	}


	int off=2*k-1;

	for (int i = 2; i <= k ; ++i)
	{
		G[1+off].push_back(i+off);
		G[i+off].push_back(1+off);
		for (int j = k+1 ; j <=2*k-1 ; ++j)
		{
			G[j+off].push_back(i+off);
			G[i+off].push_back(j+off);
		}
	}
	for (int i = k+1; i <=2*k-1 ; i+=2)
	{
		G[i+off].push_back(i+1+off);
		G[i+1+off].push_back(i+off);
	}
	G[1].push_back(2*k);
	G[2*k].push_back(1);

	int m=0;
	for (int i = 1; i <=n ; ++i)
	{
		for (int j = 0; j < G[i].size(); ++j)
		{
			int x=i,y=G[i][j];
			// cout<<"x "<<x<<" y "<<y<<endl;
			if(DP.find(pi(x,y))==DP.end() ){
				v.push_back(pi(x,y));
				DP[pi(x,y)]=1;
				DP[pi(y,x)]=1;
				m++;
			}
		}
	}
	cout<<"YES\n";
	cout<<n<<" "<<m<<endl;
	for (int i = 0; i < v.size(); ++i)
	{
		cout<<v[i].first<<" "<<v[i].second<<endl;
	}
	return 0;
}