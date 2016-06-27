#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;
typedef long long ll;
typedef pair<ll,ll> pi;
const double eps=1e-9;

ll base_rep(ll val,ll b){
	ll mul=1;
	ll rep=0;
	while(val>0){
		ll dig=val%2;
		rep+=dig*mul;
		mul*=b;
		val/=2;
	}
	return rep;
}

string str_val(ll val){
	string res="";
	while(val>0){
		ll d=val%2;
		res=to_string(d)+res;
		val/=2;
	}
	return res;
}

ll check_prime(ll n){
	for (ll i = 2; i*i <= n; ++i)
	{
		while(n%i==0){
			return i;
			n/=i;
		}
	}
	if(n>1)
		return n;
	else
		return -1;
}


int main() {
	ll t;
	cin>>t;
	for (ll cas = 1; cas <= t; ++cas)
	{
		/* code */
		ll n,j;
		cin>>n>>j;
		std::vector<std::vector<ll> > res;
		std::vector<string> res_string;
		ll found=0;
		for (ll mask = 0; mask < (1<<(n-2)) ; ++mask)
		{
			if(found==j) break;
			ll val=(mask<<1)+1+(1<<(n-1));
			std::vector<ll> temp_res;
			// temp_res.push_back();
			// cout<<"str_val "<<str_val(val)<<endl;
			// std::vector<ll> temp_value;
			for (ll i = 2; i <=10 ; ++i)
			{
				ll value=base_rep(val,i);
				ll fac=check_prime(value);
				// cout<<"i "<<i<<endl;
				if(fac==-1) break;
				temp_res.push_back(fac);
				// temp_value.push_back(value);
			}
			if (temp_res.size()==9){
				// cout<<"HI\n";
				res.push_back(temp_res);
				res_string.push_back(str_val(val));
				found++;
				// for (auto v:temp_value)
				// 	cout<<v<<" ";
				// cout<<endl;
			}
		}

		printf("Case #%lld:	\n",cas);
		for (ll i = 0; i < res.size(); ++i)
		{
			cout<<res_string[i]<<" ";
			for (ll j = 0; j < res[i].size() ; ++j)
			{
				cout<<res[i][j]<<" ";
			}
			cout<<endl;
		}
	}
	return 0;
}