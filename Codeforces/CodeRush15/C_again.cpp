#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;
typedef long long ll;


ll C,Hr,Hb,Wr,Wb;
const ll inf=1e9;
ll f(ll x,ll y){
	if(Wr*x + Wb*y>C) return -inf;
	return x*Hr+y*Hb;
}

const ll N =1000005;
int main() {
	cin>>C>>Hr>>Hb>>Wr>>Wb;
	ll 	mx=0;
	for (ll x = C/Wr; x>=max(0LL,C/Wr-1LL*N); --x)
	{
		ll y=(C-Wr*x)/Wb;
		mx=max(mx,x*Hr+y*Hb);
	}

	for (ll y = C/Wb; y>=max(0LL,C/Wb-1LL*N); --y)
	{
		ll x=(C-Wb*y)/Wr;
		mx=max(mx,x*Hr+y*Hb);
	}
	cout<<mx<<endl;
	return 0;
}