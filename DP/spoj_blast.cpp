#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;
int DP[2222][2222];
int main() {
	int lenA,lenB,k,n;
	string A,B;
	cin>>A;
	cin>>B;
	cin>>k;
	lenA=A.size();
	lenB=B.size();
	n=max(lenA,lenB);
	for (int i = 0; i <=lenA ; ++i)
	{
		DP[i][0]=k*i;
	}
	for (int i = 0; i <=lenB; ++i)
	{
		DP[0][i]=k*i;
	}
	for (int i = 1; i <=lenA; ++i)
	{
		for (int j = 1; j <= lenB; ++j)
		{
			char a,b;
			a=A[i-1];b=B[j-1];
			int minim=1e9;
			minim=min(DP[i-1][j]+k,DP[i][j-1]+k);
			minim=min(minim,abs(a-b)+DP[i-1][j-1]);
			DP[i][j]=minim;
		}
	}
	cout<<DP[lenA][lenB]<<endl;
	return 0;
}