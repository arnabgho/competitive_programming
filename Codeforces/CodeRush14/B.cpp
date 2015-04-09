#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;
std::vector<string> v;
// std::vector<int> res;
int n,m,k;
bool isValid(int i,int j){
	return 0<=i && i<n && 0<=j && j<m; 
}
int numSpider(int s){
	int ns=0;
	int j=s;
	for (int i = 1; i < n; ++i)
	{
		if(isValid(i,j-i)){
			ns+=v[i][j-i]=='R';
		}
		if(isValid(i,j+i)){
			ns+=v[i][j+i]=='L';
		}
		if(isValid(i-i,j)){
			ns+=v[i-i][j]=='D';
		}
		if(isValid(i+i,j)){
			ns+=v[i+i][j]=='U';
		}
	}
	return ns;
}

int main() {
	
	cin>>n>>m>>k;
	for (int i = 0; i < n; ++i)
	{
		string s;
		cin>>s;
		v.push_back(s);
	}
	for (int i = 0; i < m; ++i)
	{
		cout<<numSpider(i)<<" ";
	}
	cout<<endl;
	return 0;
}