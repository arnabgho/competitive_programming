#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;
typedef std::vector<int> vi;
//std::vector<vi> v(30);
std::vector<string> vs;
int v[30][30];
int rev[30][30];

void top_sort(){
	//stack<int> mystack;
	queue<int> myQ;
	string res="";
	for (int i = 0; i <26 ; ++i)
	{
		bool f=1;
		for(int j=0;j<26;j++){
			//cout<<rev[i][j]<<" ";
			if(rev[i][j]==1)
				f=0;
		}
		//cout<<endl;
		if(f)
			myQ.push(i);
	}
	//cout<<"Hi\n";
	while(!myQ.empty()){
		int u=myQ.front();
		//cout<<"u "<<u<<endl;
		myQ.pop();
		char c='a'+u;
		res=c+res;
		for (int i = 0; i < 26; ++i)
		{
			if(rev[i][u]){
				rev[i][u]=0;
			
				bool f=1;
				for(int j=0;j<26;j++){
					if(rev[i][j]==1)
						f=0;
				}
				if(f)
					myQ.push(i);
			}
		}
	}
	bool pos=1;
	for (int i = 0; i < 26 &&pos; ++i)
	{
		for (int j = 0; j <26 &&pos ; ++j)
		{
			if(rev[i][j])
				pos=0;	
		}
	}
	if(!pos)
		cout<<"Impossible\n";
	else
		cout<<res<<endl;
}

int main() {
	int n;
	cin>>n;
	string s;
	for (int i = 0; i < n; ++i)
	{
		cin>>s;
		vs.push_back(s);
	}
	//build the graph
	bool pos=1;
	for (int i = 0; i < n-1 && pos; ++i)
	{
		int x=vs[i].size();
		int y=vs[i+1].size();
		bool f=0;
		for (int j = 0; j <min(x,y) ; ++j)
		{
			if(vs[i][j]!=vs[i+1][j]){
				char a,b;
				f=1;
				a=vs[i][j]-'a';
				b=vs[i+1][j]-'a';
				//vi[a].push_back(b);
				rev[a][b]=1;
				v[b][a]=1;
				break;
			}
		}
		if(!f && y<x)
			pos=0;
	}
	if(!pos)
		cout<<"Impossible\n";
	else{
		top_sort();
	}
	return 0;
}