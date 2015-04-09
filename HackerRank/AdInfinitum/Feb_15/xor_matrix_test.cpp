#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;

int A[100][100];
int main() {
	for (int i = 0; i < 100; ++i)
	{
		for (int j = 0; j < 100 ; ++j)
		{
			cout<<(i^j)<<" ";/* code */
		}
		cout<<endl;
	}
	return 0;
}