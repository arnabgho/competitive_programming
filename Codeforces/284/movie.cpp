#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;


int main() {
	int n,x;
	std::vector<int> b,e;
	cin>>n>>x;
	for (int i = 0; i < n; ++i)
	{
		int a1,a2;
		cin>>a1>>a2;
		b.push_back(a1);
		e.push_back(a2);
	}
	int t=1;
	int i=0;
	int m=0;
	while(i<n){
		if(t==b[i]){
			t=e[i]+1;
			m+=(e[i]-b[i]+1);
			// cout<<"m "<<m<<endl;
			i++;
			continue;
		}
		if(t+x<=b[i])
			t+=x;
		else{
			t++;
			m++;
		}
	}
	cout<<m<<endl;
	return 0;
}