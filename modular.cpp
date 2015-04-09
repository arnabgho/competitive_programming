#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;
typedef long long LL;
int main() {
	LL a,b,i;
	cin>>a>>b;
	if(b>a)
		cout<<0<<endl;
	else if(b==a)
		cout<<"infinity\n";
	else{
		LL n=a-b,ans=0,sq;
		sq=sqrt(n);
		for (int i = 1; i*i <=n ; ++i)
		{
			if(n%i==0 && i>b)
				ans++;
			if(n/i>sq && n%i==0 && n/i>b)
				ans++;
		}
        cout<<ans<<endl;
	}
	return 0;
}