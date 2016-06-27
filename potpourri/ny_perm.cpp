#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;

std::vector<string> A;
int p[400];
bool visited[400];
int main() {
	int n;
	cin>>n;
	for (int i = 1; i <= n; ++i)
	{
		cin>>p[i];
	}
	for (int i = 1; i <= n; ++i)
	{
		string s="";
		cin>>s;
		A.push_back(s);
	}
	std::vector<int> res(n+1);
	pair<int,int> t;
	for (int i = 1; i <= n; ++i)
	{
		if(!visited[i]){
			std::vector<int> temp1,temp2;
			queue<pair<int,int> > myQ;
			myQ.push(make_pair(p[i],i));
			temp1.push_back(i);
			temp2.push_back(p[i]);
			visited[i]=true;
			while(!myQ.empty()){
				t=myQ.front();
				myQ.pop();
				visited[t.second]=true;
				for (int j = 1; j <=n ; ++j)
				{
					if(A[t.second-1][j-1]=='1' && !visited[j]){
						// cout<<"j "<<j<<endl;
						// cout<<"t "<<t.second<<endl;
						visited[j]=1;
						myQ.push(make_pair(p[j],j));
						temp1.push_back(j);
						temp2.push_back(p[j]);
					}
				}
			}
			sort(temp1.begin(),temp1.end());
			sort(temp2.begin(), temp2.end());
			 for(int i=0;i<temp1.size();i++){
			// 	cout<<"temp1[i] "<<temp1[i]<<endl;
			 	res[temp1[i]]=temp2[i];
			 }
			// cout<<"done\n";
		}
	}
	for (int i = 1; i <=n ; ++i)
	{
		cout<<res[i]<<" ";
	}
	cout<<endl;
	return 0;
}