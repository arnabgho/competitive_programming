#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;
typedef pair<int,int> pi;
std::vector<pi> v;
vector<int> DP(11111);
#define inf 1e9	
int main() {
	int t;
	cin>>t;
	while(t--){
		fill(DP.begin(),DP.end(),1e9);	
		v.clear();
		int N,E,F,P;
		cin>>E>>F;
		cin>>N;
		P=F-E;
		v.push_back(make_pair(0,0));
		for (int i = 0; i < N; ++i)
		{
			int p,w;
			cin>>p>>w;
			v.push_back(make_pair(w,p));
		}
		DP[0]=0;
		for (int w = 0; w <=P; ++w)
		{
			for (int i = 1; i <=N ; ++i)
			{
				if(w>=v[i].first)
					DP[w]=min(DP[w-v[i].first]+v[i].second,DP[w]);
			}
		}


		if(DP[P]==1e9)
			cout<< "This is impossible."<<endl;
		else
			cout<< "The minimum amount of money in the piggy-bank is "<<DP[P]<<"."<<endl;
	}
	return 0;
}