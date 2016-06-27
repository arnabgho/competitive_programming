#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;
const double eps = 1e-4;

double evaluate(double p,double q,double r,double s,double t,double u,double x){
	return p*exp(-x)+q*sin(x)+r*cos(x)+s*tan(x)+t*pow(x,2)+u;
}

int main() {
	double p,q,r,s,t,u;
	double lo,hi,ans;
	while(scanf("%lf %lf %lf %lf %lf %lf",&p,&q,&r,&s,&t,&u)!=EOF){
		ans=-1;
		hi=1;
		lo=0;
		while(hi-lo>eps){
			double mid=(hi+lo)/2.0;
			double val=evaluate(p,q,r,s,t,u,mid);
			double left=evaluate(p,q,r,s,t,u,lo);
			double right=evaluate(p,q,r,s,t,u,hi);
			if(val<eps)
				ans=mid	;
			if(val*left<0)
				hi=mid;
			else
				lo=mid;
		}
		std::cout << std::fixed << std::showpoint;
    	std::cout << std::setprecision(4);
		if(ans==-1)
			cout<<"No solution\n";
		
		else
			cout<<ans<<endl;
	}
	return 0;
}