#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;
typedef long long ll;
string key,target;
ll val=0;
ll B=0;
void recurse(ll pos,ll S,string tillNow){
	// cout<<tillNow<<endl;
	if(pos==S){
		ll add=0;
		for (ll i = 0; i+target.size() <=S ; ++i)
		{
			string temp=tillNow.substr(i,target.size());
			if(temp.compare(target)==0)
				add++;
		}
		val+=B-add;
		return ;
	}
	for (ll i = 0; i < key.size(); ++i)
	{
		recurse(pos+1,S,tillNow+key[i]);
	}
}

map<string,ll> gen;
int main() {
	ll T;
	cin>>T;
	for (ll cas = 1; cas <=T ; ++cas)
	{
		ll K,L,S;
		cin>>K>>L>>S;
		cin>>key>>target;
		// cout<<"Hi\n";
		B=0;
		ll l=0;
		val=0;
		ll n=target.size();
		for (ll i = 1; i < target.size(); ++i)
		{
			string s1=target.substr(0,i);
			string s2=target.substr(n-i);
			if(s1.compare(s2)==0)
				l=i;
		}
		B=1+(S-n)/(n-l);
		for (int i = 0; i < target.size(); ++i)
		{
			bool f=0;
			for (int j = 0; j <key.size() ; ++j)
			{
				if(key[j]==target[i]) f=1;
			}
			if(!f) {B=0;break;}
		}
		double den=1;
		for (ll i = 0; i < S; ++i)
		{
			den*=K;
		}
		// cout<<" B "<<B<<endl;
		recurse(0,S,"");
		double res=val/den;
		cout<<"Case #"<<cas<<": "<<res<<endl;
	}
	return 0;
}