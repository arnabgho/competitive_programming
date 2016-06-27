#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;
std::vector<int> a;
int main() {
	int n;
	cin>>n;
	for (int i = 1; i <= n; ++i)
	{
		int x;cin>>x;
		a.push_back(x);
	}
	sort(a.begin(),a.end());
	if(a[0]!=1)
		cout<<"1\n";
	
	else
		cout<<"-1\n";
	return 0;
}