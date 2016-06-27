#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;
typedef long long int LL;
int main() {
	LL t,d,p,ans,disc,disc_sq;
	bool isDiscInt;
	cin>>t;
	while(t--){
		cin>>d>>p;
		ans=0;
		disc_sq=d*d+4*p;
		if(disc_sq<0)
			ans=0;	
		else{
			disc=sqrt(d*d+4*p);
			isDiscInt=(disc*disc==disc_sq);

			if(!isDiscInt)
				ans=0;
			else if(d==0 && p==0)
				ans=1;
			else if(d==0 && p!=0){
				if(isDiscInt)
					ans=2;
				else
					ans=0;
			}
			else if(p==0 && d!=0){
				ans=3;
			}
			else if(isDiscInt){
				if(disc%2==d%2)
					ans=4;
				else
					ans=0;
			}
		}


		cout<<ans<<endl;
	}
	return 0;
}