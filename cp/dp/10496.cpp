#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;
typedef long long ll;
struct point
{
	ll x,y;
	point(){}
	point(ll X,ll Y) : x(X),y(Y){}
};
point start,limits;
ll n;
std::vector<point> v;
std::map<pair<ll,ll>,int> DP;
bool getBit(ll mask,ll i){
	return (mask>>i) & 1LL ; 
}

ll getDist(int i,int j){
	return abs(v[i].x-v[j].x)+abs(v[i].y-v[j].y);
}

ll getShortestCycle(ll cur,ll mask){
	if(DP.find(make_pair(cur,mask))!=DP.end())
		return DP[make_pair(cur,mask)];
	if(mask==( (1LL<<(n+1)) -1))
		return getDist(cur,0);
	else{
		ll minim=2e9;
		for (int i = 0; i <=n ; ++i)
		{
			if(getBit(mask,i) || i==cur) continue;
			minim=min(minim,getDist(cur,i)+getShortestCycle(i,mask|(1<<i)));
		}
		return DP[make_pair(cur,mask)]=minim;
	}
}



int main() {
	ll t;
	cin>>t;
	while(t--){
		cin>>limits.x>>limits.y;
		cin>>start.x>>start.y;
		cin>>n;
		v.clear();
		DP.clear();
		v.push_back(start);
		for (ll i = 0; i <n ; ++i)
		{
			ll x,y;
			cin>>x>>y;
			v.push_back(point(x,y));
		}
		cout<<"The shortest path has length "<<getShortestCycle(0,1)<<endl;
	}
	return 0;
}