#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;
typedef std::vector<int> vi;
std::vector<vi> A(52);
int main() {
	string s;
	cin>>s;
	for (int i = 0; i < s.size(); ++i)
	{
		if(!isupper(s[i])){
			int c=s[i]-'a';
			A[c+26].push_back(i);
		}	
		else{
			int c=s[i]-'A';
			A[c].push_back(i);
		}
	}
	int q;
	cin>>q;
	while(q--){
		string query;
		cin>>query;
		int minim=-1;
		int begin=-1;
		int end=-1;
		bool pos=1;
		for (int i=0;i<query.size() && pos;i++)
		{
			char ch=query[i];
			int c;
			if(isupper(ch)) c=ch-'A';
			else c=ch-'a'+26;
			std::vector<int>::iterator it;
			it=upper_bound(A[c].begin(),A[c].end(),minim);
			if(it==A[c].end()) pos=0;
			minim=A[c][it-A[c].begin()];
			if(i==0) begin=minim;
			if(i==query.size()-1) end=minim;
		}
		if(!pos)
			cout<<"Not matched\n";
		else
			cout<<"Matched "<<begin<<" "<<end<<endl;
	}
	return 0;
}