#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;
typedef long long int LL;
#define MOD 1000000007
std::vector<LL> A;
int DP[111][111];
int main() {
	LL n,i,k,j,p,res;
	cin>>n;
	for (i = 0; i < n; ++i)
	{
		cin>>k;
		A.push_back(k);
	}
	for(k=1;k<n;k++){
		for(i=0;i<n-k;i++){
			j=i+k;
			LL res=0;
			for(p=i;p<j;p++){
				res+=(DP[i][p]*DP[p][j])%MOD;
			}
			if(A[i]<0 && (A[j]+A[i]==0))
				res++;
			DP[i][j]=res%MOD;
		}
	}
	cout<<DP[0][n-1]<<endl;
	for ( i = 0; i < n; ++i)
	{
		for(j=0;j<n;j++)
			cout<<DP[i][j]<<" ";
		cout<<endl;	/* code */
	}
	return 0;
}