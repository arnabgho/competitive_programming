#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;

std::vector<int> d,b;
int main() {
	string s="";
	cin>>s;
	int n=s.size();
	bool even=0;
	for (int i = 0; i < s.size(); ++i)
	{
		d.push_back(s[i]-'0');
		even=even || (d[i]%2==0);
		//cout<<d[i];
	}
	//cout<<endl;
	//cout<<*(d.begin()+n-1);
	int maxpos=-1;
	int max=-1;
	for (int i = 0; i <n-1 && maxpos==-1; ++i)
	{
		if(d[i]%2==0 && d[i]<d[n-1]){
			max=d[i];
			maxpos=i;
		}
	}
	if(maxpos!=-1){
		iter_swap(d.begin()+maxpos,d.begin()+n-1);
		for (int i = 0; i < n; ++i)
		{
			cout<<d[i];
		}
		cout<<endl;
	}
	else if(even){
		int pos=-1;
		for (int i = n-1; i >=0; --i)
		{
			if(d[i]%2==0){
				pos=i;
				break;
			}
		}
		iter_swap(d.begin()+pos,d.begin()+n-1);
		for (int i = 0; i < n; ++i)
		{
			cout<<d[i];
		}
		cout<<endl;
	}
	else
		cout<<"-1"<<endl;
	return 0;
}