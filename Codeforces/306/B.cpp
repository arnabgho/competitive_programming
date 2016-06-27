#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;
std::vector<int> c(20,0);

bool getBit(int n,int i){
	return (n>>i)&1;
}

int getNumBits(int n){
	int ans=0;
	for (int i = 0; i < 20; ++i)
	{
		ans+=getBit(n,i);
	}
	return ans;
}

int main() {
	int  n, l, r, x;
	cin>>n>>l>>r>>x;
	for (int i = 0; i < n; ++i)
	{
		cin>>c[i];
	}
	long long int ans=0;
	for (int mask = 0; mask < (1<<n) ; ++mask)
	{
		if(getNumBits(mask)<2) continue;
		int diff=0;
		int mindiff=1e9,maxdiff=0;
		for (int i = 0; i < n; ++i)
		{
			if(getBit(mask,i)){
				diff+=c[i];
				mindiff=min(mindiff,c[i]);
				maxdiff=max(maxdiff,c[i]);
			}
		}
		if(l<=diff && diff<=r && maxdiff-mindiff>=x)
			ans++;
	}
	cout<<ans<<endl;
	return 0;
}