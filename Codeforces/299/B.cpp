#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;


int main() {
	string s;
	cin>>s;
	int ans=0;
	int n=s.size();
	for (int i = 1; i <n ; ++i)
	{
		ans+=(1<<i);
	}
	int k=0;
	for (int i = 0; i <s.size();++i)
	{
		if(s[i]=='7')
			k=(k<<1)+1;
		else
			k=(k<<1);
	}
	// cout<<"k "<<k<<endl;
	cout<<ans+k+1<<endl;
	return 0;
}