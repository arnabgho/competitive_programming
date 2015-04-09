#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;

int DP[1111][1111];
int arr[1111];
int main() {
	int n,i,j,t,a,ans,k;
	cin>>t;
	while(t--){
		cin>>n>>k;
		for ( i = 0; i < 1111; i++)
		{
			for( j=0;j<1111;j++) DP[i][j]=0; /* code */
		}
		for ( i = 0; i < n; i++)
		{
			cin>>a;
			arr[i]=a;/* code */
		}

		for(i=0;i<n;i++) DP[i][i]=k^arr[i];

		for(k=1;k<n;k++){
			for(i=0;i+k<n;i++){
				j=i+k;
				DP[i][j]=max(max(DP[i][j-1],DP[i-1][j]),max(DP[i][j-1]^arr[j],DP[i-1][j]^arr[i]));
			}
		}	
		ans=max(k,DP[0][n-1]);
		cout<<ans<<endl;
	}
	return 0;
}