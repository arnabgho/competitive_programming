#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;

int main() {
	int n;
	cin>>n;
	long long int ans=0;
	for (int i = 0; i < n; ++i)
	{
		int x1,y1,x2,y2;
		cin>>x1>>y1>>x2>>y2;
		ans+=(x2-x1+1)*(y2-y1+1);
	}
	cout<<ans<<endl;
	return 0;
}