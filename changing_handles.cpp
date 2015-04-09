#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;
map<string,string> myMap;
map<string,int> used;
int main() {
	int q;
	cin>>q;
	for (int i = 0; i < q; ++i)
	{
		string x,y;
		cin>>x>>y;
		myMap[x]=y;
		used[y]=1;
	}
	map<string,string>::iterator it;
	for (it = myMap.begin(); it !=myMap.end() ; ++it)
	{
		if(used.find(it->first)==used.end()){
			used[it->first]=1;
			
			string x=it->first;
			string y=x;
			used[y]=1;
			while(myMap.find(y)!=myMap.end()){
				y=myMap[y];
				used[y]=1;
			}
			cout<<x<<" "<<y<<endl;
		}
	}
	return 0;
}