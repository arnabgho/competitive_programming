#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;

int gcd(int a,int b){
	if(b==0)
		return a;
	return gcd(b,a%b);
}
typedef pair<int,int> pi;
std::map <pi, int> mymap;
std::vector<pi> points;
std::vector<bool> v(1111,0);
int main() {
	int n,x0,y0;
	cin>>n>>x0>>y0;
	for (int i = 0; i < n; ++i)
	{
		int x,y;
		cin>>x>>y;
		points.push_back(make_pair(x,y));
	}
	int x_axis=0,y_axis=0;
	for (int i = 0; i < n; ++i)
	{
		if(points[i].first==x0){
			y_axis++;
			v[i]=1;
			// cout<<"x i "<<i<<endl;
		}
		if(points[i].second==y0){
			x_axis++;
			v[i]=1;
			// cout<<"y i "<<i<<endl;
		}
	}
	int ans=0;
	ans+=(x_axis>0);
	ans+=(y_axis>0);
	// cout<<"x_axis "<<x_axis<<endl;
	// cout<<"y_axis "<<y_axis<<endl;
	for (int i = 0; i < n; ++i)
	{
		if(v[i]) continue;

		int num=points[i].first-x0;
		int den=points[i].second-y0;
		int g=gcd(abs(num),abs(den));
		num/=g;
		den/=g;
		pi p;
		if(den<0){
			num*=-1;
			den*=-1;
		}
		p=make_pair(num,den);
		// cout<<"p "<<p.first<<" "<<p.second<<endl;
		if(mymap.find(p)==mymap.end())
			ans++;
		mymap[p]=1;
	}
	cout<<ans<<endl;
	return 0;
}