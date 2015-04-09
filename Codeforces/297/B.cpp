#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;

std::vector<int> v(222222,0);
std::vector<int> cum(222222,0);

int main() {
	string s="";
	cin>>s;
	int n=s.size();
	int m;
	cin>>m;
	for (int i = 0; i <m; ++i)
	{
		int a;
		cin>>a;
		a--;
		v[a]++;
		v[n-a]--;
	}

	cum[0]=v[0];
	for (int i = 1; i <n; ++i)
	{
		cum[i]=cum[i-1]+v[i];
	}
	for (int i = 0; i < n/2; ++i)
	{
		if(cum[i]%2!=0){
			swap(s[i],s[n-i-1]);
		}
	}
	cout<<s<<endl;
	return 0;
}