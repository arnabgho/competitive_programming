#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

typedef pair<double,double> PI;
typedef pair<PI,PI> PPI;
std::vector<int> R;
std::vector<PPI> points;
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
	int r,n,m,i;
	long long ans=0;
	int x1,y1,x2,y2,d1,d2,minim,maxim,ix,iy,id;
	PI x,y;
	cin>>n;
	for (i = 0; i < n; ++i)
	{
		cin>>r;
		R.push_back(r);
	}
	cin>>m;
	for (i = 0; i < m; ++i)
	{
		cin>>x1>>y1>>x2>>y2;
		x=make_pair(x1,y1);y=make_pair(x2,y2);
		points.push_back(make_pair(x,y));
	}
	sort(R.begin(), R.end());
	for(i=0;i<m;i++){
		x1=points[i].first.first;y1=points[i].first.second;
		x2=points[i].second.first;y2=points[i].second.second;
		d1=sqrt(x1*x1+y1*y1);
		d2=sqrt(x2*x2+y2*y2);
		minim=min(d1,d2);
		maxim=max(d1,d2);

		if(x2!=x1){
			double m=(y2-y1)/(x2-x1);
			double c=y1-m*x1;
			ix=-m*c/(m*m+1);
			iy=c/(m*m+1);
			id=sqrt();
		}
		if(x1==x2){
			minim=max(minim,x1);
		}
		std::vector<int>::iterator low,up;
  		low=std::lower_bound (R.begin(), R.end(), minim); //          ^
  		up= std::upper_bound (R.begin(), R.end(), maxim); //

  		cout<<"minim: "<<minim<<endl;
  		cout<<"maxim: "<<maxim<<endl;
  		if(low==up) cout<<"0\n";
  		else cout<<up-low+1<<endl;   
	}
    return 0;
}