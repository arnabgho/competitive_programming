#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;

int DP[4000][2];
std::vector<int> A,B,C;
int countDP(int i,int previous_fed,int n){
	int maxim;
	if(i==n-1){
		if(previous_fed){
			DP[i][1]=B[i];
			return DP[i][1];
		}
		else{
			DP[i][0]=A[i];
			return DP[i][0];
		}
	}
	if(previous_fed){
		if(DP[i+1][1]==-1)	countDP(i+1,1,n);
		if(DP[i+1][0]==-1)  countDP(i+1,0,n);
		DP[i][1]=max(DP[i+1][1]+B[i],DP[i+1][0]+C[i]);
		return DP[i][1];
	}
	else{
		if(DP[i+1][1]==-1)	countDP(i+1,1,n);
		if(DP[i+1][0]==-1)  countDP(i+1,0,n);
		DP[i][0]=max(DP[i+1][1]+A[i],DP[i+1][0]+B[i]);
		return DP[i][0];
	}
}
int main() {
	int n,num;
	cin>>n;
	memset (DP,-1,sizeof(DP));
	for (int i = 0; i < n; ++i)
	{
		cin>>num;A.push_back(num);/* code */
	}
	for (int i = 0; i < n; ++i)
	{
		cin>>num;B.push_back(num);/* code */
	}
	for (int i = 0; i < n; ++i)
	{
		cin>>num;C.push_back(num);/* code */
	}
	int ans=countDP(0,0,n);
	cout<<ans<<endl;
	return 0;
}