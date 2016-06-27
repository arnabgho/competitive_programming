#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;
std::vector<int> v(1100);
int n;
bool checkConf(){
	for (int i = 0; i < n; ++i)
	{
		if(v[i]!=i) return 0;
	}
	return 1;
}
void rotate(){
	for (int i = 0; i < n; ++i)
	{
		if(i%2==0)
			v[i]=(v[i]+1)%n;
		else
			v[i]=(v[i]+n-1)%n;
	}
}
void printConf(){
	for (int i = 0; i < n; ++i)
	{
		cout<<v[i]<<" ";
	}
	cout<<"\n";
}
int main() {
	cin>>n;
	for (int i = 0; i < n; ++i)
	{
		cin>>v[i];
	}
	bool pos=0;
	for (int i = 0; i < 2*n && !pos; ++i)
	{
		if(checkConf())
			pos=1;
		// printConf();
		rotate();
	}
	if(pos)
		cout<<"Yes\n";
	else
		cout<<"No\n";
	return 0;
}