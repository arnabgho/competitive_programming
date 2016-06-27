#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;
typedef long long ll;
map<ll,ll> DP;
int main() {
	ll n,m;
	string s;
	cin>>n>>m;
	cin>>s;
	ll tot=0;
	for (int i = 0; i < n; ++i)
	{
		if(s[i]!='.') continue;
		ll p=i;
		DP[p]=1;
		while(i+1<n && s[i+1]=='.'){
			DP[p]++;
			i++;
		}
		tot+=DP[p]-1;
	}
	if(n==1){
		for (int i = 0; i < m; ++i)
		{
			int pos;
			char ch;
			cin>>pos>>ch;
			cout<<"0\n";
		}
		return 0;
	}
	for (int i = 0; i < m; ++i)
	{
		int pos;
		char ch;
		cin>>pos>>ch;
		pos--;
		map<ll,ll>::iterator it;
		if( (s[pos]!='.' && ch!='.') || (s[pos]=='.' && ch=='.') ){
			tot=tot;
		}
		else if(s[pos]=='.' && ch!='.'){
			// cout<<"Case 1\n";
			it=DP.upper_bound(pos);
			--it;
			ll beg=it->first;
			ll len=it->second;
			// cout<<"beg "<<beg<<" len "<<len<<" pos "<<pos<<endl;
			DP[beg]=pos-beg;
			if(len>1)
				tot-=len-1;

			if(beg+len-1-pos>0){
				DP[pos+1]=beg+len-1-pos;
				if(DP[pos+1]>1)
					tot+=DP[pos+1]-1;
			}	
			if(DP[beg]>1)
				tot+=DP[beg]-1;
			if(DP[beg]==0) {
				// cout<<"erased\n";
				DP.erase(DP.find(beg));
				bool f= (DP.find(beg)!=DP.end());
				// cout<<"find "<< f<<endl;
			}

		}
		else if(s[pos]!='.' && ch=='.'){
			// cout<<"Case 2\n";
			it=DP.upper_bound(pos);
			--it;
			ll beg=it->first;
			ll len=it->second;

			// cout<<"beg "<<beg<<" len "<<len<<" pos "<<pos<<endl;
			if(beg+len==pos){
				tot++;
				DP[beg]++;
			}

			it=DP.upper_bound(pos);
			if(it!=DP.end()) {
				ll rbeg=it->first;
				ll rlen=it->second;

				// cout<<"rbeg "<<rbeg<<" rlen "<<rlen<<" rpos "<<pos<<endl;
				if(rbeg==pos+1){
					tot++;
					DP[pos]=rlen+1;
					DP.erase(DP.find(rbeg));
				}

				if(rbeg==pos+1 && beg+len==pos){
					// tot--;
					DP[beg]+=DP[pos];
					DP.erase(DP.find(pos));
				}
			}
		}
		cout<<tot<<endl;
		s[pos]=ch;
	}
	return 0;
}