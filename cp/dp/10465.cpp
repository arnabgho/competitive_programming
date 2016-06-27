#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;
std::vector<int> DP(11000,0);
std::vector<int> wasted(11000,0);
typedef pair<int,int> pi;
int main() {
	int m,n,t;
	while(scanf("%d %d %d",&m,&n,&t)!=EOF){
		fill(DP.begin(),DP.end(),0);
		fill(wasted.begin(),wasted.end(),0);
		for (int i = 1; i <=t ; ++i)
		{
			std::vector<pi> v;
			if(i>=n)
				v.push_back(pi(-wasted[i-n],1+DP[i-n]));
			if(i>=m)
				v.push_back(pi(-wasted[i-m],1+DP[i-m]));
			v.push_back(pi(-wasted[i-1]-1,DP[i-1]));
			sort(v.rbegin(),v.rend());
			DP[i]=v[0].second;
			wasted[i]=-v[0].first;
		}
		if(wasted[t]==0)
			printf("%d\n",DP[t]);
		else
			printf("%d %d\n",DP[t],wasted[t]);
	}
	return 0;
}