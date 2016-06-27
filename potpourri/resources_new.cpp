#include <stdio.h>
#include <iostream>
#include <algorithm>

#define INF 100000000000;

using namespace std;

typedef pair<long long int,long long int> PII;



int main(){

	int n;	
	long long int x,y;
	cin>>n;
	long long int l,x_min,x_max,y_min,y_max,l_y,l_x;
	x_min=INF;
	x_max=-INF;
	y_max=-INF;
	y_min=INF;
	while(n--){
		cin>>x>>y;
		if(x>x_max)
			x_max=x;
		if(x<x_min)
			x_min=x;
		if(y>y_max)
			y_max=y;
		if(y<y_min)
			y_min=y;
	}
	l_y=y_max-y_min;
	l_x=x_max-x_min;
	l=max(l_x,l_y);
	cout<<l*l<<endl;
	return 0;
}	