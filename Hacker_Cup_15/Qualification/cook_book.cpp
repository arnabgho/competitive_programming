#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
typedef long long int ll;
int main() {
	int t;
	cin>>t;
	for(int cas=1;cas<=t;cas++){
		ll n;
		string s;
		cin>>s;
		n=stoll(s);
		ll maxim=n,minim=n;
		int sz=s.size();
		for (int i = 0; i <sz ; ++i)
		{
			string temp=s;
			for (int j = i+1; j <sz ; ++j)
			{
				if(i==0 && s[j]=='0') continue;
				swap(temp[i],temp[j]);
				ll t=stoll(temp);
				swap(temp[i],temp[j]);
				if(t<minim)
					minim=t;
				if(t>maxim)
					maxim=t;
			}
		}
		cout<<"Case #"<<cas<<": "<<minim<<" "<<maxim<<endl;
	}
	return 0;
}