#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;
std::vector<int> w;
std::vector<int> b;
std::map<int, int> mymap;
int main() {
	int n,m,x;
	cin>>n>>m;
	for (int i = 0; i < n; ++i)
	{
		cin>>x;
		w.push_back(x);	
	}
	for (int i = 0; i < m; ++i)
	{
		cin>>x;
		b.push_back(x);
	}
	std::vector<int> v;
	for (int i = 0; i < m; ++i)
	{
		if(mymap[b[i]]==0){
			mymap[b[i]]=1;
			v.push_back(b[i]);
		}
	}
	int sum=0;
	for (int i = 0; i < m; ++i)
	{
		//w[i-1]
		int pos=0;
		for (int j = 0; j <v.size() ; ++j)
		{
			if(v[j]==b[i]){
				pos=j;
				break;
			}
			sum+=w[v[j]-1];
		}
		v.erase(v.begin()+pos);
		reverse(v.begin(),v.end());
		// for (int j = 0; j < v.size(); ++j)
		// {
		// 	cout<<v[j]<<endl;
		// }
		v.push_back(b[i]);
		// cout<<" =-----------------\n"; 
		reverse(v.begin(),v.end());
		// for (int j = 0; j < v.size(); ++j)
		// {
		// 	cout<<v[j]<<endl;
		// }
		// cout<<" =-----------------\n"; 
	}
	cout<<sum<<endl;
	return 0;
}