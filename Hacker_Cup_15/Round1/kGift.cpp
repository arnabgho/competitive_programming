#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;
bool isPal(string s){
	int n=s.size();
	for (int i = 0; i < n/2; ++i)
	{
		if(s[i]!=s[n-i-1])
			return false;
	}
	return true;
}

int main() {
	cin>>s;
	int n=s.size();
	bool found=false;
	string res="";
	for (char ch = 'a'; ch <='z' && !found; ++ch)
	{
		for (int i = 0; i < count && !found; ++i)
		{
			string l=s.substr(0,i);
			l+=ch;
			l+=s.substr(i);
			if(isPal(l)){
				found=true;
				res=l;
			}
		}
	}
	if(found)
		cout<<res<<endl;
	else
		cout<<"NA\n";
	return 0;
}