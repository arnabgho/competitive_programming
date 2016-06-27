#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;
std::vector<double> v;
int n;
const double eps=1e-6;
double check(double x){
	double val=v[0];
	for (int i = 1; i <=n; ++i)
	{
		val+=v[i]/pow(1.0+x,i);
	}
	return val;
}

int main() {
	cin>>n;
	while(n!=0){
		v.clear();
		for (int i = 0; i <=n; ++i)
		{
			double x;cin>>x;v.push_back(x); 
		}
		double lo=-1,hi=1e9,ans=-1;
		while(hi-lo>eps){
			double mid=(hi+lo)/2.0;
			if(check(mid)>0)
				lo=mid;
			else hi=mid;
			if(check(mid)<eps)
				ans=mid;
		}
		std::cout << std::fixed << std::showpoint;
    	std::cout << std::setprecision(2);
		if(ans==-1)
			cout<<"No\n";
		else
			cout<<ans<<endl;
		cin>>n;
	}
	return 0;
}