#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;

int main() {
	int T;
	cin>>T;
	while(T--){
		string s;
		cin>>s;
		int pC=0,pO=0;
		bool tie;
		for (int i = 0; i < s.size(); ++i)
		{
			if(pC==10 && pO==10)
				tie=1;
			if(s[i]=='1')
				pC++;
			else
				pO++;
		}
		// cout<<"pC "<<pC<<endl;
		// cout<<"pO "<<pO<<endl;
		if(!tie){
			if(pC>pO)
				cout<<"WIN\n";
			else
				cout<<"LOSE\n";
		}
		else{
			if(s[s.size()-1]=='0')
				cout<<"LOSE\n";
			else
				cout<<"WIN\n";
		}
	}
	return 0;
}