#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;
std::vector<int> v;
bool DP[11000][110];
int main() {
	int m;
	cin>>m;
	while(m--){
		int n,k;
		cin>>n>>k;
		v.clear();
		for (int i = 0; i < n; ++i){
			int x;cin>>x;v.push_back(x);
		}
		memset(DP,0,sizeof(DP));
		int rem=((v[0])%k+3*k)%k;
		DP[0][rem]=1;
		for (int i = 1; i < n; ++i)
		{
			for (int j = 0; j < k; ++j)
			{
				if(DP[i-1][j]){
					int rem=((v[i]+j)%k+3*k)%k;
					DP[i][rem]=1;
					rem=((-v[i]+j)%k+3*k)%k;
					DP[i][rem]=1;
				}
			}
		}
		if(DP[n-1][0])
			cout<<"Divisible\n";
		else
			cout<<"Not divisible\n";
	}
	return 0;
}