#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;
typedef pair<int,int> pi;

multiset<pi> v[2]; 

multiset<pi> s[2];
int main() {
	int n,x;
	int t,h,m;
	cin>>n>>x;
	for (int i = 0; i < n; ++i)
	{
		cin>>t>>h>>m;
		v[t].insert(pi(m,h));
		s[t].insert(pi(m,h));
	}
	int mx0=0;
	int cur=x;
	int turn=0;
	// set<pi>::iterator it;
	//start with 0
	while(1){
		if(s[turn].size()==0)
			break;
		bool f=0;
		for (multiset<pi>::reverse_iterator it=s[turn].rbegin(); it !=s[turn].rend() ; ++it)
		{
			pi p=*it;
			if(p.second<=cur){
				mx0++;
				f=1;
				cur+=p.first;
				s[turn].erase(p);
				break;
			}
		}
		if(!f) break;
		turn=(turn+1)%2;
	}
	//start with 1
	s[0]=v[0];s[1]=v[1];
	cur=x;
	int mx1=0;
	turn=1;

	while(1){
		if(s[turn].size()==0)
			break;
		bool f=0;
		for (multiset<pi>::reverse_iterator it=s[turn].rbegin(); it !=s[turn].rend() ; ++it)
		{
			pi p=*it;
			if(p.second<=cur){
				mx1++;
				f=1;
				cur+=p.first;
				s[turn].erase(p);
				break;
			}
		}
		if(!f) break;
		turn=(turn+1)%2;
	}

	cout<<max(mx0,mx1)<<endl;
	return 0;
}