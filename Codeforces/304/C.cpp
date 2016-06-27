#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;
typedef pair<vector<int>,vector<int> > pq;
map<pq,int> DP;
const int LIM=100;
int main() {
	int n;
	int k1,k2;
	cin>>n;
	cin>>k1;
	vector<int> q1,q2;
	for (int i = 0; i < k1; ++i)
	{
		int x;
		cin>>x;
		q1.push_back(x);
	}
	cin>>k2;
	for (int i = 0; i < k2; ++i)
	{
		int x;
		cin>>x;
		q2.push_back(x);
	}
	DP[pq(q1,q2)]=1;
	bool infLoop=0;
	int ans=0;
	int win=-1;
	// int i=0;
	while(!q1.empty() && !q2.empty() && !infLoop){
		// i++;
		// cout<<"HI\n";
		int x,y;
		// for(auto x:q1){
		// 	cout<<x<<" ";
		// }
		// cout<<endl;
		// for(auto x:q2){
		// 	cout<<x<<" ";
		// }
		// cout<<endl;
		x=*q1.begin();q1.erase(q1.begin());
		y=*q2.begin();q2.erase(q2.begin());

		if(x>y){
			q1.push_back(y);q1.push_back(x);
		}
		else{
			q2.push_back(x);q2.push_back(y);
		}
		ans++;
		if(q1.empty()) win=2;
		if(q2.empty()) win=1;
		if(DP.find(pq(q1,q2))!=DP.end())
			infLoop=1;
		DP[pq(q1,q2)]=1;
	}
	if(infLoop) cout<<"-1\n";
	else cout<<ans<<" "<<win<<endl;
	return 0;
}