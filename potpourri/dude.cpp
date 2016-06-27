#include <bits/stdc++.h>

using namespace std;

#define      pii               std::pair<int,int>
#define      vi                std::vector<int>
#define      mp(a,b)           std::make_pair(a,b)
#define      X                 first
#define      Y                 second

typedef long long LL;

vi List[100011];
int pre[100011];
int ans[100011];

void window(int n, int m)
{
	map<int,int> mp;
	for(int i=0;i<n;++i)
		pre[i] = -1;
	int j = 0;
	for(int i=0;i<n;++i){
		while(j < n and mp.size() < m){
			for(int k=0;k<List[j].size();++k){
				mp[List[j][k]] += 1;
			}
			j += 1;
		}
		if(mp.size() < m) return ;
		pre[i] = j;
		for(int j=0;j<List[i].size();++j){
			assert(mp.count(List[i][j]) == true);
			mp[List[i][j]] -= 1;
			if(mp[List[i][j]] == 0) mp.erase(mp[List[i][j]]);
		}
	}
	mp.clear();
}

void solve()
{
	int n, m;
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;++i){
		int x, y; 
		scanf("%d",&x);
		while(x--){
			scanf("%d",&y);
			List[i].push_back(y-1);
		}
	}
	window(n, m);
	ans[0] = 0;
	printf("%d %d\n",0+1, pre[0]);
	for(int i=1;i<n;++i)
	{
		int e = pre[ans[i-1]];
		if(e-1 >= i){
			ans[i] = ans[i-1];
			printf("%d %d\n",ans[i]+1, pre[ans[i]]);
			continue;
		}
		int l = 0, r = i-1, m;
		while(r-l > 1){
			m = (l+r) >> 1;
			if(pre[m]-1 <= i) r = m;
			else l = m;
		}
		if(pre[l]-1 >= i) ans[i] = l;
		else if(pre[r]-1 <= i) ans[i] = r;
		else{
			if(pre[i] == -1) break;
			else ans[i] = i;
		}
		printf("%d %d\n",ans[i]+1, pre[ans[i]]);
	}

	for(int i=0;i<n;++i) List[i].clear();
}

int main()
{
	int T;
	cin >> T;
	while(T--){
		solve();
	}
	return 0;
}