#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;

int main() {
	int T;
	cin>>T;
	while(T--){
		string s;
		cin>>s;
		if(s.size()==1){
			cout<<min(s[0]-'0',9-(s[0]-'0'))<<endl;
		}
		else{
			int n=s.size();
			int sum=0;
			for (int i = 1; i <n ; ++i)
			{
				sum+=s[i]-'0';
			}
			int first=s[0]-'0';
			int m=(sum+first)%9;
			int ans=1e9;
			if(m==0)
				cout<<"0\n";
			
			else{
				//if need to be increased 
				if(9-m<=9-first+9*(n-1)-sum){
					ans=9-m;
				}

				//if need to be decreased
				if(m<=first-1+sum){
					ans=min(ans,m);
				}
				cout<<ans<<endl;
			}
			
		}
	}
	return 0;
}