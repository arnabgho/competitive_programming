#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;

int main() {
	int n;
	string b;
	cin>>n;
	cin>>b;
	bool f=0;
	for (int j = 1; j <=25 && !f ; ++j)
	{
		for (int i = 0; i+4*j <n && !f ; ++i)
		{
			if(b[i]=='*' && b[i+j]=='*' && b[i+2*j]=='*' && b[i+3*j]=='*' && b[i+4*j]=='*') f=1;
		}
	}
	if(f)
		cout<<"yes"<<endl;
	else
		cout<<"no"<<endl;
	return 0;
}