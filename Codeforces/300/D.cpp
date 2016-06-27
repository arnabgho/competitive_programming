#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;
std::vector<string> v;
std::vector<string> res;
int n;
bool isValid(int i,int j){
	return 0<=i && i<n && 0<=j && j<n;
}

bool checkValid(){
	std::vector<string> new_v=v;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j <n ; ++j)
		{
			if(new_v[i][j]=='x') new_v[i][j]='.';
		}
	}
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if(new_v[i][j]!='o') continue;
			for (int k = 0; k < n ; ++k)
			{
				for (int l = 0; l <n ; ++l)
				{
					if(new_v[k][l]=='o') continue;
					if(res[k-i+n-1][l-j+n-1]=='x') new_v[k][l]='x';
				}
			}
		}
	}
	for (int i = 0; i < n; ++i)
	{
		if(v[i].compare(new_v[i])!=0)
			return 0;
	}
	return 1;
}

int main() {
	cin>>n;
	for (int i = 0; i < n; ++i)
	{
		string s;
		cin>>s;
		v.push_back(s);
	}
	string s="";
	for (int i = 0; i < 2*n-1; ++i)
	{
		s+='x';
	}
	for (int i = 0; i < 2*n-1; ++i)
	{
		res.push_back(s);
	}
	res[n-1][n-1]='o';
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if(v[i][j]!='o') continue;
			for (int k = 0; k <n ; ++k)
			{
				for (int l = 0; l < n; ++l)
				{
					if(v[k][l]!='.') continue;
					res[k-i+n-1][l-j+n-1]='.';
				}
			}
		}
	}
	if(!checkValid()) cout<<"NO\n";
	else{
		cout<<"YES\n";
		for (int i = 0; i < res.size(); ++i)
		{
			cout<<res[i]<<endl;
		}
	}
	return 0;
}