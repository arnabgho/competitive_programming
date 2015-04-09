#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
		string s="";
		cin>>s;
		int n=s.size();
		string a="";
		string b="";
		for (int i = 0; i <n ; ++i)
		{
			if(i%2==0){
				a+='+';b+='-';
			}
			else if(i%2==1){
				a+='-';b+='+';
			}
		}
		int vala=0,valb=0;
		for (int i = 0; i < n; ++i)
		{
			vala+=(a[i]!=s[i]);
			valb+=(b[i]!=s[i]);
		}
		cout<<min(vala,valb)<<endl;
	}	
	return 0;
}