#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;

int main() {
	int n;
	cin>>n;
	string a;
	string b;
	cin>>a;
	cin>>b;
	int res=0;
	for (int i = 0; i < n; ++i)
	{
		int x,y;
		x=a[i]-'0';
		y=b[i]-'0';
		// cout<<"x "<<x<<" y "<<" val "<<min(abs(x-y),min(abs(10+y-x),abs(10+x-y)) )<<endl;
		res=res+min(abs(x-y),min(abs(10+y-x),abs(10+x-y)) );
	}
	cout<<res<<endl;
	return 0;
}