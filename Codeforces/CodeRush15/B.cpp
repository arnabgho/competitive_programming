#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;


std::vector<int> a(100000);
vector<int> node(100000);
int main() {
	int n;
	cin>>n;
	for (int i = 2; i <= (1<<(n+1) )-1 ; ++i)
	{
		cin>>a[i];
	}
	// int mx=0;
	// for (int i = (1<<n); i < (1<<(n+1)) ; ++i)
	// {
	// 	int val=0;
	// 	int l=i;
	// 	while(l>1){
	// 		val+=a[l];
	// 		l/=2;
	// 	}
	// 	mx=max(mx,val);
	// }
	int val=0;
	for (int l = n; l >0 ; --l)
	{
		for (int i = (1<<l); i < (1<< (l+1) ); i+=2)
		{
			// cout<<"i "<<i<<" l "<<l<<endl;
			int m=max(node[i]+a[i],node[i+1]+a[i+1]);
			val+=m-min(node[i]+a[i],node[i+1]+a[i+1]);
			// cout<<"m "<<m<<endl;
			node[i/2]=m;
		}
	}
	cout<<val<<endl;
	return 0;
}