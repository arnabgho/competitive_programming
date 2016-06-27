#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;

int main() {
	int n,m;
	cin>>n>>m;
	string a="";
	string b="#";
	string c="";
	for (int i = 0; i < m; ++i)
	{
		a+='#';
	}
	for (int i = 1; i < m; ++i)
	{
		b+='.';
	}
	for (int i = 0; i < m-1; ++i)
	{
		c+='.';
	}
	c+='#';
	for (int i = 0; i < n; ++i)
	{
		if(i%2==0){
			cout<<a<<endl;
		}
		else if(i%4==1)
			cout<<c<<endl;
		else if(i%4==3)
			cout<<b<<endl;
	}
	return 0;
}