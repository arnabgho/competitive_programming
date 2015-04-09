#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;

typedef std::vector<double> vd;

std::vector<vd> z(3000,vd(3000,0));
int main() {
	int n,t;
	double p;
	cin>>n>>p>>t;
	z[0][0]=1;
	for (int i = 1; i <=t; ++i)
	{
		for (int j = 0; j <=n; ++j)
		{
			if(j>0 && j<n)
				z[i][j]=(1.0-p)*z[i-1][j]+p*z[i-1][j-1];
			else if(j==n){
				z[i][j]=z[i-1][j]+p*z[i-1][j-1];
			}
			else{
				z[i][j]=(1.0-p)*z[i-1][j];
			}
		}
	}
	double ans=0;	

	// for (int i = 1; i <=t; ++i)
	// {
	// 	for (int j = 0; j <=n; ++j)
	// 	{
	// 		cout<<z[i][j]<<" ";
	// 	}
	// 	cout<<endl;
	// }		

	for (int i = 1; i <=n ; ++i)
	{
		ans+=i*z[t][i];/* code */
		// cout<<"i "<<i<<" z "<<z[t][i]<<endl;
	}
	std::cout.precision(7);
	std::cout << std::fixed;
	cout<<ans<<endl;
	return 0;
}