#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;

int main() {
	int n,m;
	n=500000;
	m=500000;
	string s="";
	cout<<n<<" "<<m<<endl;
	for (int i = 0; i < n; ++i)
	{
		if(rand()%2)
			s+='a'+rand()%26;
		else
			s+='.';
	}
	cout<<s<<endl;
	for (int i = 0; i < m; ++i)
	{
		int pos=1+rand()%n;
		char ch;
		if(rand()%2)
			ch='a'+rand()%26;
		else
			ch='.';
		cout<<pos<<" "<<ch<<endl;
	}
	return 0;
}