#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;
std::vector<int> v;
int n;
bool check(int k){
	int cur_k=k;
	for (int i = 1; i <= n; ++i)
	{
		if(v[i]-v[i-1]>k) return 0;
		k=(v[i]-v[i-1]==k) ? (k-1):k;
	}	
	return 1;
}

int main() {
	int t;
	cin>>t;
	for (int cas = 1; cas <=t ; ++cas)
	{
		v.clear();
		cin>>n;
		v.push_back(0);
		for (int i = 0; i < n; ++i)
		{
			int x;cin>>x;v.push_back(x);
		}
		int hi,lo,ans;
		hi=v[n];
		lo=0;
		ans=1e9;
		while(lo<hi){
			int mid=lo+(hi-lo)/2;
			if(check(mid)){
				hi=mid;
				ans=min(ans,mid);
			}
			else
				lo=mid+1;
		}
		cout<<"Case "<<cas<<": "<<ans<<endl;
	}
	return 0;
}