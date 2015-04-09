#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector> 
#include <stdlib.h>
using namespace std;

struct ob
{
	long long int a,b;
};
bool cmp(struct ob x,struct ob y){
	return x.a<y.a || (x.a==y.a && x.b<y.b);
}

int main(){
	int n,i;
	std::vector<struct ob> v;
	struct ob* newob;
	cin>>n;
	for(i=1;i<=n;i++){
		newob=(struct ob *)malloc(sizeof(struct ob));
		cin>>newob->a;
		cin>>newob->b;
		v.push_back(*newob);
	}
	stable_sort(v.begin(), v.end(),cmp);
	int pos=1;
	for(i=1;i<n && pos;i++)
		pos=pos&&(v[i-1].b<=v[i].b);
	if(pos)
		cout<<v[n-1].b<<endl;
	else
		cout<<v[n-1].a<<endl;
	return 0;
}