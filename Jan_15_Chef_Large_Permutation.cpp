#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;
typedef long long int ll;
std::vector<int> v(111111);
int main() {
	ll t;
	cin>>t;
	while(t--){
		ll N,k;
		cin>>N>>k;
		

		// cout<<"N "<<N<<endl;
		fill(v.begin(),v.end(),0);
		for (int i = 0; i < k; ++i)
		{
			cin>>v[i];
		}
		if(k==0){
			ll check=(N*(N+1))/2LL+1;
			if(check%2==0)
				cout<<"Mom\n";
			else
				cout<<"Chef\n";
			continue;
		}
		sort(v.begin(),v.begin()+k);
		ll cum=0;
		ll ans=(N*(N+1))/2LL+1LL;
		ll sum=0;
		// cout<<"ans "<<ans<<endl;
		bool found=false;
		for (int i = 0; i < k; ++i)
		{
			ll n=v[i];
			cum+=n;
			sum=n*(	n+1);
			sum=sum/2LL;
			sum-=cum;

			while(i<k && v[i+1]==v[i]+1){
				i++;
				cum+=v[i];
			}
			n=v[i]+1;
			// cout<<"n "<<n<<" sum "<<sum<<endl;
			if(n>sum+1){
				found=true;
				ans=sum+1;break;
			}
		}
		
		if(k>0 && !found){
			sum=(N*(N+1))/2LL+1LL;
			ans=sum-cum;
		}
		if(ans%2==0)
			cout<<"Mom"<<endl;
		else
			cout<<"Chef"<<endl;
	}
	return 0;
}