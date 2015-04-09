#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;

double value(int t,int k,double p){
	double d_t=t;
	double d_k=k;
	double val=1;
	for (double i = 1; i <= d_k; ++i)
	{
		val*=(p*(t-k+i))/i;
	}
	for (int i = 0; i < t-k; ++i)
	{
		val*=(1-p);
	}
	return val;
}

int main() {
	double p;
	int n,t;
	cin>>n>>p>>t;
	double ans=0;
	if(t<=n){
		for (int k = 1; k <=t ; ++k)
		{
			ans+=k*value(t,k,p);
		}
	}
	else if(t>n){
		for (int k = 1; k <=n-1 ; ++k)
		{
			ans+=k*value(t,k,p);
		}
		for (int k = n-1; k<= t-1; ++k)
		{
			ans+=n*value(k,n-1,p)*p;
		}
	}
	std::cout.precision(7);
	std::cout << std::fixed;
	cout<<ans<<endl;
	return 0;
}