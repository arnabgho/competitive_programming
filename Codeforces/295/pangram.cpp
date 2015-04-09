#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;

int main() {
	int n;
	string s;
	cin>>n>>s;
	std::map<char, int> mymap;
	for (int i = 0; i < n; ++i)
	{
		mymap[tolower(s[i])]=1;
	}
	bool pos=1;
	for (char c = 'a'; c<='z' ; ++c){
		if(mymap.find(c)==mymap.end())
			pos=0;
	}
	if(pos)
		cout<<"YES\n";
	else
		cout<<"NO\n";
	return 0;
}