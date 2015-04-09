#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;

std::map<char, int> S;
std::map<char, int> T;

int main() {
	string s,t;
	cin>>s;
	cin>>t;
	for (int i = 0; i < t.size(); ++i)
	{
		T[t[i]]++;
	}
	for (int i = 0; i < s.size(); ++i)
	{
		S[s[i]]++;
	}
	int y=0,w=0;
	
	for (char x = 'a'; x <= 'z' ; ++x)
	{
		int p=T[x];
		int q=S[x];
		
			T[x]-=min(p,q);
			S[x]-=min(p,q);
			y+=min(p,q);
	}

	for (char x = 'A'; x <= 'Z' ; ++x)
	{
		int p=T[x];
		int q=S[x];
		
			T[x]-=min(p,q);
			S[x]-=min(p,q);
			y+=min(p,q);
	}

	for (char x = 'a'; x <= 'z' ; ++x)
	{
		char z=toupper(x);
		// cout<<"z "<<z<<endl; 
		int p=T[z];
		int q=S[x];
		// cout<<"p "<<p<<" q "<<q<<endl;
			T[y]-=min(p,q);
			S[x]-=min(p,q);
			w+=min(p,q);
		
	}

	for (char x = 'A'; x <= 'Z' ; ++x)
	{
		char z=tolower(x);
		// cout<<"z "<<z<<endl; 		
		int p=T[z];
		int q=S[x];
		// cout<<"p "<<p<<" q "<<q<<endl;
			T[z]-=min(p,q);
			S[x]-=min(p,q);
			w+=min(p,q);
	}


	cout<<y<<" "<<w<<endl;
	return 0;
}