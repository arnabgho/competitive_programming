#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;
int LPS[4000][4000];
int longestPalSub(string s){
	memset(LPS,0,sizeof(LPS));
	int n=s.size();
	// cout<<"s "<<s<<endl;
	for (int i = 0; i <n ; ++i)
	{
		LPS[i][i]=1;
	}
	for (int i = 1; i < n; ++i)
	{
		for (int j = 0; j+i <n ; ++j)
		{
			int k=j+i;
			if(s[j]==s[k]){
				LPS[j][k]=LPS[j+1][k-1]+2;
			}
			LPS[j][k]=max(max(LPS[j][k-1],LPS[j+1][k]),LPS[j][k]);
		}
	}
	// cout<<"LPS "<<LPS[0][n-1]<<endl;
	return LPS[0][n-1];
}

int main() {
	string s;
	int maxim=0;
	cin>>s;
	int n=s.size();
	string s1=s;
	string s2="";
	for (int i = 1; i <n ; ++i)
	{	
		s2+=s1[0];
		s1.erase(s1.begin());
		int left=longestPalSub(s1);
		int right=longestPalSub(s2);
		maxim=max(maxim,left*right);
	}
	cout<<maxim<<endl;
	return 0;
}