#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;
struct point
{
	double x,y;
	point(double a,double b) : x(a),y(b){}	
};
#define PI 3.14159265
#define DEG PI / 180.0
std::vector<double> l(7);
std::vector<point> points;
std::vector<double> A(5);
int main() {
	for (int i = 1; i <=6 ; ++i)
	{
		cin>>l[i];
	}
	points.push_back(point(-1,-1));
	points.push_back(point(0,0));
	points.push_back(point(-l[2]*cos(60.0*DEG),l[2]*cos(30.0*DEG)));
	points.push_back(point((l[3]-l[2])*cos(60.0*DEG) , (l[3]+l[2])*cos(30.0*DEG)));
	points.push_back(point( l[4] + (l[3]-l[2])*cos(60.0*DEG)  , (l[3]+l[2])*cos(30.0*DEG)  ));
	points.push_back(point( l[4] + (l[3]-l[2]+l[5])*cos(60.0*DEG) , (l[3]+l[2]-l[5])*cos(30.0*DEG)  ) );
	points.push_back(point(l[1],0));

	A[1]=0.5*abs(points[1].x*( points[2].y-points[3].y ) + points[2].x*(points[3].y- points[1].y)  + points[3].x*(points[1].y-points[2].y)  );
	A[2]=0.5*abs(points[1].x*( points[3].y-points[4].y ) + points[3].x*(points[4].y- points[1].y)  + points[4].x*(points[1].y-points[3].y)  );
	A[3]=0.5*abs(points[1].x*( points[4].y-points[6].y ) + points[4].x*(points[6].y- points[1].y)  + points[6].x*(points[1].y-points[4].y)  );
	A[4]=0.5*abs(points[4].x*( points[5].y-points[6].y ) + points[5].x*(points[6].y- points[4].y)  + points[6].x*(points[4].y-points[5].y)  );

	double areaT=0.5*cos(30.0*DEG);
	double areaTot=A[1]+A[2]+A[3]+A[4];
	// cout<<"areaTot "<<areaTot<<endl;
	// cout<<"areaT "<<areaT<<endl;
	int numTriangles=round(areaTot/areaT);
	// for(auto a:A) cout<<"a "<<a<<endl;
	cout<<numTriangles<<endl;
	return 0;
}