#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;

typedef long long int LL;
typedef pair<LL,LL> PI;
std::vector<PI> Pairs;
int main() {
	LL n,m,i,besta,bestb,a,b,num;
	cin>>n;
	for (i = 0; i < n; ++i)
	{
		cin>>num;
		Pairs.push_back(make_pair(num,0));
	}
	cin>>m;
	for (i = 0; i < m; ++i)
	{
		cin>>num;
		Pairs.push_back(make_pair(num,1));
	}
	sort(Pairs.begin(), Pairs.end());
	a=besta=3*n;
	b=bestb=3*m;

	for (i = 0; i < n+m;i++)
	{
		// cout<<Pairs[i].first<<" " <<Pairs[i].second<<endl;
		if(Pairs[i].second==1)
			b--;
		if(Pairs[i].second==0)
			a--;
		if(a-b>besta-bestb){
			besta=a;
			bestb=b;
		}
		// cout<<a<<":"<<b<<endl;
	}
	cout<<besta<<":"<<bestb<<endl;
	return 0;
}