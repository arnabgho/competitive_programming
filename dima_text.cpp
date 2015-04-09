#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;

std::vector<string> v;
int main() {
	int n;
	string temp;
	string s="<3";
	cin>>n;
	for (int i = 0; i < n; ++i)
	{	
		cin>>temp;
		s+=temp+"<3";
	}
	string message="";
	cin>>message;
	int first=0;
	int second=0;
	int matched=0;
	// cout<<s<<endl;
	// cout<<message<<endl;
	while(first<s.size() && second<message.size()){
		if(s[first]==message[second]){
			// cout<<s[first]<<endl;
			first++;second++;matched++;
		}
		else second++;
	}
	if(matched==s.size())
		cout<<"yes\n";
	else
		cout<<"no\n";
	return 0;
}