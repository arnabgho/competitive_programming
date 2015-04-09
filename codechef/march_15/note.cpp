#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;
typedef long long ll;

int main() {
	ll t;
	cin>>t;
	while(t--){
		ll X,Y,K,N;
		//cin>>X>>Y>>K>>N;
		scanf("%lld %lld %lld %lld",&X,&Y,&K,&N);
		ll remP=X-Y;
		ll remR=K;
		bool found=false;
		ll P,C;	
		for (int i = 0; i < N; ++i)
		{
			// cin>>P>>C;
			scanf("%lld %lld",&P,&C);
			if(!found && P>= remP && C<=remR)
				found=true;
		}
		if(found)
			cout<<"LuckyChef\n";
		else
			cout<<"UnluckyChef\n"; 
	}
	return 0;
}