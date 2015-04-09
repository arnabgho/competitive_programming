#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;

int main() {
	double L,S1,S2;
	int n;
	double S,q;
	cin>>L>>S1>>S2;
	S=abs(S1-S2);
	cin>>n;
	for (int i = 0; i <n ; ++i)
	{	
		cin>>q;
		double sq2,t;
		sq2=sqrt(2);
		t=sq2*(L-sqrt(q));
		t/=S;
		//cout<<t<<endl;
		printf("%.6lf\n",t );
	}
	return 0;
}';[]'