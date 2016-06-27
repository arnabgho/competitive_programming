#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;

map<pair<string,string>,bool> DP;

bool check_equiv(string a,string b){
	if(DP.find(make_pair(a,b))!=DP.end())
		return DP[make_pair(a,b)];
	if(a.size()%2==1)
		return DP[make_pair(a,b)]= (a.compare(b)==0);
	if(a.compare(b)==0)
		return  DP[make_pair(a,b)]=1;
	int n=a.size();
	string left_a=a.substr(0,n/2);
	string right_a=a.substr(n/2);
	string left_b=b.substr(0,n/2);
	string right_b=b.substr(n/2);
	return  DP[make_pair(a,b)]=(check_equiv(left_a,left_b) && check_equiv(right_a,right_b) ) || ( check_equiv(left_a,right_b) && check_equiv(right_a,left_b)  ); 
}

int main() {
	string a,b;
	cin>>a>>b;
	bool pos=check_equiv(a,b);
	if(pos) cout<<"YES\n";
	else cout<<"NO\n";
	return 0;
}