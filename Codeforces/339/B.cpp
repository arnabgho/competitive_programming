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

std::vector<string> v;

int check_beau(string s){
	std::vector<int> pos_ones;
	int i;
	for (i = 0; i < s.size(); ++i)
	{
		if(s[i]=='1')
			pos_ones.push_back(i);
		if(s[i]!='1' && s[i]!='0')
			return -1;
	}
	if(pos_ones.size()>1)
		return -1;
	else if(pos_ones.size()==1)
		return s.size()-pos_ones[0]-1;
}

bool check_all_zero(string s){
	for (int i = 0; i < s.size(); ++i)
	{
		if(s[i]!='0') return false;
	}
	return true;
}

int main(){
	int n;
	cin>>n;
	for (int i = 0; i < n; ++i)
	{
		string s;
		cin>>s;
		v.push_back(s);
	}
	int num_zero=0;
	string non_beau="";
	bool found_non_beau=false;
	bool all_zero=false;
	for (int i = 0; i < n; ++i)
	{
		if(check_all_zero(v[i])){
			all_zero=true;
			num_zero=1;
			break;
		}

		if(check_beau(v[i])==-1){
			found_non_beau=true;
			non_beau=v[i];
			// cout<<"hi\n";
			// cout<<non_beau<<endl;
		}
		else
			num_zero+=check_beau(v[i]);
	}
	// cout<<"num_zero "<<num_zero<<endl;
	if(!found_non_beau && !all_zero)
		cout<<"1";

	else if(!all_zero)
		cout<<non_beau;

	for (int i = 0; i < num_zero; ++i)
	{
		cout<<"0";
	}
	cout<<endl;
	return 0;	
}
