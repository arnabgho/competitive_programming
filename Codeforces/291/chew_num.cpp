#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;

int main() {
	long long int n;
	long long int res=0;
	long long int p=1;
	cin>>n;
	while(n>=10){
		int d=n%10;
		int x=min(d,9-d);
		res=x*p+res;
		n/=10;
		p*=10;
	}
	//cout<<"n "<<n<<endl;
	if(n==9)
		res+=p*9;
	else
		res+=min(n,9-n)*p;
	cout<<res<<endl;
	return 0;
}
