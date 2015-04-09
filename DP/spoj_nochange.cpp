#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;
std::vector<int> v;
std::vector<bool> dp(211111);
int sum[10];
int N,K;

bool solve(){
    sum[0] = v[0];
    for(int i=1;i<K;++i){
        sum[i] = sum[i-1] + v[i];
    }
    for(int i=0;i<=N;++i){
        dp[i] = 0;
    }
    dp[0] = 1;
    for(int i=0;i<=N;++i){
        if(dp[i]) dp[i+v[0]] = 1;
    }
    for(int k=1;k<K;++k){
        for(int i=0;i<=N;++i){
            if(!dp[i]) continue;
            int u = i + sum[k];
            // if(u>N) break;
            dp[u] = 1;
        }
    }
    return dp[N];
}



int main() {
	cin>>N>>K;
	while(K--){
		int x;
		cin>>x;
		v.push_back(x);
	}
	if(solve())
		cout<<"YES\n";
	else
		cout<<"NO\n";
	return 0;
}