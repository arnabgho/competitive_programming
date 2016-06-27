#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;

int main() {
	int arr[]={2,7,2,3,3,4,2,5,1,2};
	string s;
	cin>>s;
	int ans=1;
	ans*=(arr[s[0]-'0']);
	ans*=(arr[s[1]-'0']);
	cout<<ans<<endl;
	return 0;
}