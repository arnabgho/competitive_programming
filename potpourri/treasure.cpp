#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;
std::vector<int> res(111111,0);
std::vector<int> newres(111111,0);
int main() {
	string s;
	cin>>s;
	int n=s.size();
	int unmatched_right=0;
	int unmatched_left=0;
	int numH=0;
	bool pos=true;
	int count=0;
	int last=-1;
	res[0]=(s[0]=='(') ? 1:-1;
	count=(s[0]=='#');	
	for (int i = 1; i < n; ++i)
	{
		if(s[i]=='('){
			res[i]=res[i-1]+1;
		}
		else
			res[i]=res[i-1]-1;
		if(s[i]=='#')
			count++;
	}	
	for (int i =0; i < n && pos; ++i)
	{
		if(res[i]<0){
			pos=false;
		}
		cout<<"res "<<res[i]<<endl;
	}
	if(!pos)
		cout<<"-1\n";
	else{
		for (int i = 0; i <n ; ++i)
		{
			
		}
	}	
	return 0;
}