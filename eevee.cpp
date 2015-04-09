#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;

int main() {
	string arr[8]={"vaporeon", "jolteon", "flareon", "espeon", "umbreon", "leafeon", "glaceon", "sylveon"};
	string s;
	int i,j,n,num=0;
	cin>>n;
	cin>>s;
	for (i = 0; i < s.size(); ++i)
	{
		if(s[i]!='.')
			num++;/* code */
	}
	for(i=0;i<8;i++){
		int c=0;
		if(arr[i].size()!=n) continue;
		for(j=0;j<s.size();j++){
			if(arr[i][j]!='.'){
				if(arr[i][j]==s[j]) c++;
			}
		}
		if(c==num){
			cout<<arr[i]<<endl;break;
		}
	}
	return 0;
}