#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;
typedef long long ll;
char vow[5]={'a','e','i','o','u'};
set<char> vowels(vow,vow+5);
std::vector<ll> v(1111111,0);
std::vector<ll> res(1111111,0);
std::vector<ll> accum(1111111,0);
int main() {
	ll T;
	cin>>T;
	for (ll cas = 1; cas <=T ; ++cas)
	{
		fill(v.begin(),v.end(),0);fill(res.begin(),res.end(),0);fill(accum.begin(),accum.end(),0);
		string s;
		ll k,n;
		cin>>s>>k;
		n=s.size();
		for (ll i = 0; i < n; ++i)
		{
			if(vowels.find(s[i])==vowels.end())
				v[i+1]=1;
			
			accum[i+1]=accum[i]+v[i+1];
		}
		ll y=0;
		for (ll i = n-k+1; i >=1 ; --i)
		{
			// check for next k char 
			if(accum[i+k-1]-accum[i-1]==k)
				res[i]=n-(i+k)+2;
			else
				res[i]=res[i+1];
			y+=res[i];
		}
		cout<<"Case #"<<cas<<": "<<y<<endl;
	}
	return 0;
}