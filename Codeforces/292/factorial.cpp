#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;

int main() {
	int n;
	map<char,string> myMap;
	string s="";
	cin>>n;
	string k;
	cin>>k;
	myMap['0']="";
	myMap['1']="";
	myMap['2']="2";
	myMap['3']="3";
	myMap['4']="322";
	myMap['5']="5";
	myMap['6']="53";
	myMap['7']="7";
	myMap['8']="7222";
	myMap['9']="7332";
	for (int i = 0; i < k.size(); ++i)
	{
		s+=myMap[k[i]];
	}
	sort(s.rbegin(),s.rend());
	cout<<s<<endl;
	return 0;
}