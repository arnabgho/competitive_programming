#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;
std::vector<vector<char> > v;


void addCont(char ch){
	for (int i=0;i<v.size();i++)
	{
		if(v[i].back()>=ch){
			v[i].push_back(ch);
			return ;
		}
	}
	vector<char> s;
	s.push_back(ch);
	v.push_back(s);
}

int main() {
	string s;
	cin>>s;
	int cas=0;
	while(s.compare("end")!=0){
		v.clear();
		for(auto ch:s)
			addCont(ch);
		int res=v.size();
		printf("Case %d: %d\n",cas,res);
		cin>>s;
		cas++;
	}
	return 0;
}