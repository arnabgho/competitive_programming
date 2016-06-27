#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;
struct rect{
	int a,b;
};
int main() {
	std::vector<rect> v(3); 
	for (int i = 0; i < 3; ++i)
	{
		cin>>v[i].a>>v[i].b;
	}
	bool pos=false;
	// a1 base
	if(v[1].a+v[2].a<=v[0].a && max(v[1].b,v[2].b)<=v[0].b)
		pos=1;
	if(v[1].b+v[2].a<=v[0].a && max(v[1].a,v[2].b)<=v[0].b)
		pos=1;
	if(v[1].a+v[2].b<=v[0].a && max(v[1].b,v[2].a)<=v[0].b)
		pos=1;
	if(v[1].b+v[2].b<=v[0].a && max(v[1].a,v[2].a)<=v[0].b)
		pos=1;
	
	// b1 base

	if(v[1].a+v[2].a<=v[0].b && max(v[1].b,v[2].b)<=v[0].a)
		pos=1;
	if(v[1].b+v[2].a<=v[0].b && max(v[1].a,v[2].b)<=v[0].a)
		pos=1;
	if(v[1].a+v[2].b<=v[0].b && max(v[1].b,v[2].a)<=v[0].a)
		pos=1;
	if(v[1].b+v[2].b<=v[0].b && max(v[1].a,v[2].a)<=v[0].a)
		pos=1;

	if(pos) cout<<"YES\n";
	else cout<<"NO\n";
	return 0;
}