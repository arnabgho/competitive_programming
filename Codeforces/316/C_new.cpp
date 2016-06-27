#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;
typedef long long ll;
set <int> DP;
int main() {
	ll n,m;
	string s;
	cin>>n>>m;
	cin>>s;
	ll tot=0;
	DP.insert(0);DP.insert(n+1);
	for (int i = 0; i < n; ++i)
	{
		if(s[i]!='.'){ DP.insert(i); continue;}
		ll p=1;
		while(i+1<n && s[i+1]=='.'){
			p++;
			i++;
		}
		tot+=p-1;
	}

	for (int i = 0; i < m; ++i)
	{
		int pos,num;
		char ch;
		cin>>pos>>ch;
		int l,r;
		pos--;
		set<int>::iterator it1,it2,it3;
		if( (s[pos]!='.' && ch!='.') || (s[pos]=='.' && ch=='.') ){
			tot=tot;
		}
		else if(s[pos]=='.' && ch!='.'){
			l=*DP.lower_bound(pos);
			r=*DP.upper_bound(pos);
			num=r-l-1;
			if(num>1){
				tot-=num-1;
			}
			DP.insert(pos);
			
			if(pos-l-1>1)
				tot+=pos-l-2;
			if(r-pos-1>1)
				tot+=r-pos-2;
		}
		else if(s[pos]!='.' && ch=='.'){
			l=*DP.lower_bound(pos-1);
			r=*DP.upper_bound(pos);
		
			if(pos-l-1>1)
				tot-=pos-l-2;
			if(r-pos-1>1)
				tot-=r-pos-2;
			DP.erase(DP.find(pos));
			if(r-l-1>1)
				tot+=r-l-2;
		}
		cout<<tot<<endl;
	}

	return 0;
}