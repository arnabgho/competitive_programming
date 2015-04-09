#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
		string s,r;
		cin>>s;
		r=s;
		reverse(s.begin(),s.end());
		bool pos=1;
		for (int i = 1; i < s.size(); ++i)
		{
			if(abs(s[i]-s[i-1])!=abs(r[i]-r[i-1]))
				pos=0;
		}
		if(pos) cout<<"Funny\n";
		else cout<<"Not Funny\n";
	}
	return 0;
}