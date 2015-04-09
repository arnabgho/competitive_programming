#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;
typedef long long ll;
string s;
int n;
ll dp[300][300]={{0}};

bool found=false;
void solve(){
	for (int i = 0; i < n-1; ++i)
	{
		// if(s[i]==')' || s[i]==']' || s[i]=='}')
		// 	continue;
		if(s[i]=='(' && (s[i+1]==')' || s[i+1]=='?'))
			dp[i][i+1]=1;
		else if(s[i]=='{' && (s[i+1]=='}' || s[i+1]=='?'))
			dp[i][i+1]=1;
		else if(s[i]=='[' && (s[i+1]==']' || s[i+1]=='?'))
			dp[i][i+1]=1;
		else if(s[i]=='?' &&  (s[i+1]==')' || s[i+1]=='}' ||s[i+1]==']' ))
			dp[i][i+1]=1;
		else if(s[i]=='?' && s[i+1]=='?')
			dp[i][i+1]=3;
	}

	for (int l = 2; l <n ; ++l)
	{
		for (int i = 0; (i+l) < n; ++i)
		{
			int j=i+l;
			ll val=0;
			for (int k = i+1; k <= j-1; ++k)
			{
				if(s[i]=='(' && (s[k]==')' || s[k]=='?') )
					val+=dp[i+1][k-1]*dp[k+1][j];
				else if(s[i]=='{' && (s[k]=='}' || s[k]=='?'))
					val+=dp[i+1][k-1]*dp[k+1][j];
				else if(s[i]=='[' && (s[k]==']' || s[k]=='?')   )
					val+=dp[i+1][k-1]*dp[k+1][j];
				else if(s[i]=='?' && (s[k]==')' || s[k]=='}' ||s[k]==']' ))
					val+=dp[i+1][k-1]*dp[k+1][j];
				else if(s[i]=='?' && s[k]=='?')
					val+=3*dp[i+1][k-1]*dp[k+1][j];
			}
			if(val>100000){
				found=true;
				val%=100000;
			}
			dp[i][j]=val;
		}
	}
}

int main() {
	cin>>n;
	cin>>s;
	solve();

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}

	if(!found)
		cout<<dp[0][n-1]<<endl;
	else{
		string l=std::to_string(dp[0][n-1]);
		int sz=l.size();
		for (int i = 0; i < 5-sz; ++i)
		{
			l='0'+l;
		}
		cout<<l<<endl;
	}
	return 0;
}