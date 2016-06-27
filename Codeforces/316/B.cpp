#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;
typedef long long ll;

int main() {
	ll n,m;
	cin>>n>>m;
	ll left,right;
	left=m-1;
	right=n-m;
	if(n+m==2)
		cout<<"1\n";
	else if(left>=right)
		cout<<m-1<<endl;
	else
		cout<<m+1<<endl;
	return 0;
}