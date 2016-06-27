#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;

int dp[200][200];
int a[200];
int main() {
	int n,k;
	cin>>n>>k;
	for (int i = 1; i <= n; ++i)
	{
		cin>>a[i];
	}
	bool pos=true;
	for(int col=1;col<=k && pos;col++){
		int minim=1e9;
		for (int i = 1; i <=n && pos; ++i)
		{
			//if(a[i]==0) continue;
			minim=min(minim,a[i]);
		}
		int val=minim+1;
		for (int i = 1; i <=n ; ++i)
		{
			if(a[i]==0) continue;
			if(a[i]>=val){
				a[i]-=val;
				dp[i][col]=val;
				continue;
			} 
			a[i]-=val-1;
			dp[i][col]=val-1;
		}
	}	
	for (int i = 1; i <=n ; ++i)
	{
		if(a[i]>0) pos=false;
	}

	// for (int i = 1; i <=n ; ++i)
	// {
	// 	for (int j = 1; j <= k; ++j)
	// 	{
	// 		cout<<dp[i][j]<<" ";
	// 	}
	// 	cout<<endl;
	// }
	if(!pos){
		cout<<"NO\n";
	}
	else{
		cout<<"YES\n";
		for (int i = 1; i <=n ; ++i)
		{
			for (int col = 1; col <=k; ++col)
			{
				for (int j = 1; j <=dp[i][col] ; ++j)
				{
					cout<<col<<" ";
				}
			}
			cout<<endl;
		}
	}
	return 0;
}