#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;

int main() {
	double a,b,c,d,p_m,p_v;
	cin>>a>>b>>c>>d;
	p_m=max(0.3*a,a-0.004*c);
	p_v=max(0.3*b,b-0.004*c);
	if(p_v>p_m)
		cout<<"Vasya\n";
	else if(p_m>p_v)
		cout<<"Misha\n";
	else
		cout<<"Tie\n";
	return 0;
}