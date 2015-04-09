#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;

typedef long long ll;
typedef pair<char,char> pc;
map<pc,int> DP;
ll Hamming(string s,string t){
	ll ans=0;
	for (int i = 0; i < s.size(); ++i)
	{
		ans+=(s[i]!=t[i]);/* code */
	}
	return ans;
}

int main() {
	int n;
	cin>>n;
	string s,t;
	cin>>s>>t;
	// string s="",t="";
	
	// cout<<"_s "<<_s<<endl;
	// cout<<"_t "<<_t<<endl;

	// cout<<"s "<<s<<endl;
	// cout<<"t "<<t<<endl;
	n=s.size();
	for (int i = 0; i < n; ++i)
	{
		char a=s[i];
		char b=t[i];
		DP[pc(a,b)]=i;
	}
	ll H=Hamming(s,t);
	bool f=0;
	for (int i = 0; i < n; ++i)
	{
		char a=s[i];
		char b=t[i];
		if(a==b) continue;
		if(DP.find(pc(b,a))!=DP.end() && DP[pc(b,a)]!=i){
			f=1;
			cout<<H-2<<endl;
			cout<<(i+1)<<" "<<DP[pc(b,a)]+1<<endl;
			return 0;
		}
	}

	f=0;
	for (int i = 0; i < n; ++i)
	{
		if(s[i]==t[i]) continue;
		char a=s[i];
		for (char b ='a'; b <= 'z'; ++b)
		{
			if(b==a) continue;
			
			pc p=pc(b,a);
			if(DP.find(p)!=DP.end() && DP[p]!=i){
				f=1;
				cout<<H-1<<endl;
				cout<<i+1<<" "<<DP[p]+1<<endl;
				return 0;
			}
		}
	}
	cout<<H<<endl;
	cout<<"-1 -1\n";
	return 0;
}