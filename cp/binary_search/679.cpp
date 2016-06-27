#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;

int main() {
	int d,I,l;
	cin>>l;
	for (int i = 0; i < l; ++i)
	{
		cin>>d>>I;
		I--;
		int pos=1;
		for (int j = 0; j < d-1; ++j)
		{
			bool bit=I%2;
			if(!bit) pos*=2;
			else pos=pos*2+1;
			I/=2;
		}
		cout<<pos<<endl;
	}
	return 0;
}