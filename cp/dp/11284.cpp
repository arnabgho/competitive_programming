#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;

typedef long long ll;
double dist[55][55];
double cost[55][55];
std::vector<int> v;
std::vector<double> gain;
int n,m;
std::map<pair<ll,double>,int> DP;

bool getBit(ll mask,ll i){
	return (mask>>i) & 1LL ; 
}

ll getDist(int i,int j){
	return dist[i][j];
}

double getShortestCycle(ll cur,ll mask){
	if(DP.find(make_pair(cur,mask))!=DP.end())
		return DP[make_pair(cur,mask)];
	if(mask==( (1LL<<(n+1)) -1))
		return -cost[cur][0];
	else{
		double maxim=-2e9;
		for (int i = 0; i <=n ; ++i)
		{
			int current=v[cur];
			int next=v[i];
			if(getBit(mask,i) || i==cur) continue;
			maxim=max(maxim,max(getShortestCycle(i,mask|(1<<i))-cost[cur][i]+gain[i-1], getShortestCycle(i,mask|(1<<i)) ));
		}
		return DP[make_pair(cur,mask)]=maxim;
	}
}




int main() {
	int t;
	cin>>t;
	while(t--){
		memset(dist,1e9,sizeof(dist));
		DP.clear();
		v.clear();
		gain.clear();
		int N,M;
		cin>>N>>M;
		for (int i = 0; i < M; ++i)
		{
			int x,y;
			double d;
			cin>>x>>y>>d;
			dist[x][y]=d;
			dist[y][x]=d;
		}
		int P;
		cin>>P;
		// v.push_back(0);
		// gain.push_back(0);
		for (int i = 0; i < P; ++i)
		{
			int store;
			double val;
			cin>>store>>val;
			v.push_back(store);
			gain.push_back(val);
		}
		for(auto x:v) cout<<"store "<<x<<endl;
		for(auto x:gain) cout<<"gain "<<x<<endl;	
		// Floyd Warshall
		for (int k = 0; k <= N ; ++k)
		{
			for (int i = 0; i <=N ; ++i)
			{
				for (int j = 0; j <=N ; ++j)
				{
					dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
				}
			}
		}

		 // cost from/to home to/from every store where a opera is available
		for (int i = 0; i < P; i++)
			cost[0][i + 1] = cost[i + 1][0] = dist[0][ v[i] ];
		// cost between stores where a opera is available
		for (int i = 1; i <= P; i++)
			for (int j = 1; j <= P; j++)
				cost[i][j] = dist[ v[i - 1] ][ v[j - 1] ];
		n=P;
		double best=getShortestCycle(0,1);
		std::cout << std::fixed << std::showpoint;
	    std::cout << std::setprecision(2);
		if(best<=0)
			cout<<"Don't leave the house\n";
		else
			cout<<"Daniel can save $"<<best<<endl;
	}
	return 0;
}