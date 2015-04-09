#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;
std::map<int, int> A,B,C;
std::vector<int> a,b,c;
int main() {
	int n;
	cin>>n;
	for (int i = 0; i < n; ++i)
	{
		int x;
		cin>>x;
		a.push_back(x);
		A[x]++;
	}
	for (int i = 0; i < n-1; ++i)
	{
		int x;
		cin>>x;
		b.push_back(x);
		B[x]++;
	}

	for (int i = 0; i < n-2; ++i)
	{
		int x;
		cin>>x;
		c.push_back(x);
		C[x]++;
	}

	int f=0,s=0;
	for (int i = 0; i < n; ++i)
	{
		int x=a[i];
		// cout<<"x "<<x<<" A "<<A[x]<<" B "<<B[x]<<endl;
		if(A[x]!=B[x])
			f=x;
	}
	for (int i = 0; i < n-1; ++i)
	{
		int x=b[i];
		if(B[x]!=C[x])
			s=x;
	}
	cout<<f<<endl;
	cout<<s<<endl;
	return 0;
}