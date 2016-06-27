#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;
typedef long long ll;
std::vector<int> l;
map<int,int> T[300];
map<int,int> DP;
int main() {
	int n;
	cin>>n;
	for (int i = 0; i < n; ++i)
	{
		int x;
		// cin>>x;
		scanf("%d",&x);
		l.push_back(x);
		DP[x]++;
	}
	for (int i = 0; i < n; ++i)
	{
		int x;
		// cin>>x;
		scanf("%d",&x);
		T[x][l[i]]++;
	}
	int ans=1e9;
	std::map<int,int>::reverse_iterator rit;
	int sum=0;
	int nremoved=0;
	for (rit = DP.rbegin(); rit !=DP.rend() ; ++rit)
	{
		int l=rit->first;
		int k=rit->second;
		int rem=max(0,n-nremoved-2*k+1);
		int val=0;
		// cout<<"rem "<<rem<<endl;
		for (int i = 1; i <=200 && rem>0 ; ++i)
		{
			for (map<int,int>::iterator it = T[i].begin(); it !=T[i].end() && rem>0; ++it)
			{
				if(it->first==l)
					continue;
				else{
					int p=min(it->second,rem);
					val+=i*p;
					rem-=p;
				}
			}
		}
		ans=min(ans,sum+val);
		for (int i = 1; i <= 200; ++i)
		{
			// while(T[i].find(l)!=T[i].end()){
			// 	sum+=i;
			// 	nremoved++;
			// 	T[i].erase(T[i].find(l));
			// }
			nremoved+=T[i][l];
			sum+=i*T[i][l];
			T[i].erase(T[i].find(l));
		}
		// cout<<"sum "<<sum<<endl;
	}
	// cout<<ans<<endl;
	printf("%d\n",ans );
	return 0;
}