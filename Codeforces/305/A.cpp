#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;

bool checkPal(string s){
	string orig=s;
	reverse(s.begin(), s.end());
	// cout<<"orig "<<orig<<endl;
	// cout<<"reverse "<<s<<endl;
	return s.compare(orig)==0;	
}

int main() {
	string s;
	int k;
	cin>>s;
	cin>>k;
	int n=s.size();
	if(n%k!=0){
		cout<<"NO\n";
		return 0;
	}
	int len=n/k;
	bool f=1;
	for (int i = 0; i < n; i+=len)
	{
		string t=s.substr(i,len);
		if(!checkPal(t))
			f=0;
	}
	if(f)
		cout<<"YES\n";
	else
		cout<<"NO\n";
	return 0;
}