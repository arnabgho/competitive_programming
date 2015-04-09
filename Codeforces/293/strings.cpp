#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;

int main() {
	string s,t;
	cin>>s>>t;
	bool eq=1;
	string res=s;
	for (int i = 0; i < s.size(); ++i)
	{
		if(eq && s[i]==t[i])
			continue;
		if(s[i]!=t[i]){
			eq=0;
			if(t[i]-s[i]==1){
				bool alla=1;
				bool allz=1;
				for (int j = i+1; j < s.size(); ++j)
				{
					if(t[j]!='a')
						alla=0;
					if(s[j]!='z')
						allz=0;
					t[j]='a';
					s[j]='z';
				}

				if(alla && allz)
					cout<<"No such string\n";
				else{
					if(!alla)
						cout<<t<<endl;
					else if(!allz)
						cout<<s<<endl;
				}
			}
			else{
				res[i]=s[i]+1;
				cout<<res<<endl;
			}
			break;
		}
	}
	return 0;
}