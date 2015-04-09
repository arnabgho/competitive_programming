#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;

int main() {
	int x,y,t,E,N;
	cin>>E>>N;
	int ans=0;
	for (int x = 0; x <= min(E,N/2); ++x)
	{
		int E_rem,N_rem;
		E_rem=E-x;
		N_rem=N-2*x;
		if(E_rem<0 || N_rem<0) continue;
		y=min(E_rem/2,N_rem);
		ans=max(ans,x+y);
	}
	cout<<ans<<endl;
	return 0;
}