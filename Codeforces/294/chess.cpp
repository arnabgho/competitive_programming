#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;
std::map<char, int> mymap;
int main() {
	'q', 'r', 'b', 'n', 'p', 'k',
	mymap['q']=9;
	mymap['r']=5;
	mymap['b']=3;
	mymap['n']=3;
	mymap['p']=1;
	mymap['k']=0;
	int w=0,b=0;
	string s;
	while(cin>>s){
		for (int i = 0; i < s.size(); ++i)
		{
			if(s[i]=='.') continue;
			char c=tolower(s[i]);
			if(isupper(s[i])){
				w+=mymap[c];
			}
			else{
				b+=mymap[c];
			}
		}
	}
	if(w>b)
		cout<<"White\n";
	else if(w<b)
		cout<<"Black\n";
	else
		cout<<"Draw\n";		 

	return 0;
}