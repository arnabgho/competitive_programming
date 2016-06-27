#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;

int main() {
	 
	double n,m,ans;
	cin>>n>>m;
	if(n==1 && m==1)
		ans=1;
	else{
		double k=n;
		ans=1.0/k+((k-1)*(m-1))/(k*(m*n-1));
	}
	cout << fixed << showpoint;
    cout << setprecision(8);
	cout<<ans<<endl;
	return 0;
}