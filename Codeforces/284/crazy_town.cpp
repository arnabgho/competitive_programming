#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;

struct line
{
	double a,b,c;	
};
const double eps=1e-9;
typedef pair<double,double> pd;
std::vector<line> v;
std::vector<pd> inter;

bool isBetween(pd a,pd b,pd c){
	double dotproduct = (c.first - a.first) * (b.first - a.first) + (c.second - a.second)*(b.second - a.second);
    if (dotproduct < 0) 
    	return 0;
    double squaredlengthba = (b.first - a.first)*(b.first - a.first) + (b.second - a.second)*(b.second - a.second);
    if (dotproduct > squaredlengthba) 
    	return 0;
    return 1;
}

int main() {
	double x1,y1,x2,y2;
	cin>>x1>>y1;
	cin>>x2>>y2;
	int n;
	cin>>n ;
	for (int i = 0; i < n; ++i)
	{
		line l;
		cin>>l.a>>l.b>>l.c;
		v.push_back(l);
	}
	line s;
	s.a=y1-y2;
	s.b=x2-x1;
	s.c=x1*y2-x2*y1;
	for (int i = 0; i < n; ++i)
	{
		double x,y;
		double den=v[i].a*s.b-v[i].b*s.a;
		if(abs(den)<eps)
			continue;
		x=-v[i].c*s.b+v[i].b*s.c;
		y=v[i].c*s.a-v[i].a*s.c;
		x/=den;
		y/=den;
		// cout<<"x "<<x<<" y "<<y<<endl; 
		pd p=make_pair(x,y);
		inter.push_back(p);
	}
	int ans=0;
	//std::vector<bool> considered(inter.size(),0);
	for (int i = 0; i <inter.size() ; ++i)
	{
		pd p1,p2;
		p1=make_pair(x1,y1);
		p2=make_pair(x2,y2);
		ans+=isBetween(p1,p2,inter[i]);
	}
	cout<<ans<<endl;
	return 0;
}