#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;
std::vector<bool> v(111111,0);
int main() {
	string s,t,p;
	cin>>s>>t;
	int n=s.size();
	int ans=0;
	for (int i = 0; i < n; ++i)
	{
		if(s[i]!=t[i]){ans++;v[i]=1;}
	}
	if(ans%2==1){
		cout<<"impossible\n";
		return 0;
	}
	p=s;
	int c=0;
	for (int i = 0; i < n; ++i)
	{
		if(c==ans/2)
			break;
		if(v[i]){
			if(s[i]=='0') p[i]='1';
			else p[i]='0';
			c++;
		}
	}
	cout<<p<<endl;
	return 0;
}