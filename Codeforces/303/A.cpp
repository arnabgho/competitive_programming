#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;
int A[200][200];
std::vector<bool> v(200);
int main() {
	int n;
	cin>>n;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j <n ; ++j)
		{
			cin>>A[i][j];
		}
	}
	int ans=n;
	for (int i = 0; i <n ; ++i)
	{
		for (int j = 0; j <n ; ++j)
		{
			if(A[i][j]==1) v[i]=1;
			if(A[i][j]==2) v[j]=1;
			if(A[i][j]==3){v[i]=1;v[j]=1;}
		}
	}
	cout<<n-accumulate(v.begin(),v.end(),0)<<endl;
	for (int i = 0; i < n; ++i)
	{
		if(!v[i])
			cout<<i+1<<" ";
	}
	cout<<endl;
	return 0;
}