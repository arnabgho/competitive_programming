#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
#define fi first
#define se second
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
const ll mod=1000000007;
ll powmod(ll a,ll b) {ll res=1;a%=mod;for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
// head

string switch_reverse(string s){
	reverse(s.begin(),s.end());
	string res="";
	for (int i = 0; i <s.size() ; ++i)
	{
		if(s[i]=='0')
			res+='1';
		else
			res+='0';
	}
	return res;
}

string init(){
	string s="0";
	int c=0;
	while(s.size()<1e5){
		s=s+'0'+switch_reverse(s);
	}
	return s;
}

int main(){
	int test;
	cin>>test;
	string s=init();
	for (int cas = 1; cas <= test; ++cas)
	{
		int k;
		cin>>k;
		printf("Case #%d: %c\n",cas,s[k-1] );
	}
	return 0;	
}
