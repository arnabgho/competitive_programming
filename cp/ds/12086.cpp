#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;

typedef long long ll;
typedef std::vector<ll> vl;
ll LSOne(ll n){
	return (n & (-n));
}

class FenwickTree{
private:vl ft;ll size;
public:
	FenwickTree(ll n){ll size=n;ft.assign(n+1,0);}
	ll rsq(ll b){
		ll sum=0;
		for (; b; b-=LSOne(b)) sum+=ft[b];
		return sum;	
	}
	ll rsq(ll a,ll b){return rsq(b)- ( a==1 ? 0:rsq(a-1) ) ;}
	void adjust(ll k,ll v){
		// for(auto x:ft) cout<<x<<endl;
		// cout<<"--------\n";
		for (; k <ft.size() ; k+=LSOne(k)) ft[k]+=v;
		// for(auto x:ft) cout<<x<<endl;
		// cout<<"--------\n";	
	}
};


int main() {
	vl num;
	for(ll cas=1;cas<=cas;cas++){
		ll n;
		cin>>n;
		if(n==0) break;
		num.assign(n+1,0);
		FenwickTree * ft=new FenwickTree(n);
		for (ll i = 1; i <= n; ++i)
		{
			ll r;
			scanf("%lld",&r);
			ft->adjust(i,r);
			num[i]=r;
		}
		string s;
		printf("Case %lld:\n",cas );
		while(getline(cin,s)){
			if (s.compare("END")==0) break;
			if (s.compare("")==0) continue;
			char ch;
			ll a,b;
			sscanf(s.c_str(),"%c %lld %lld",&ch,&a,&b);
			if (ch=='S'){ ft->adjust(a,b-num[a]); num[a]=b;}

			else if(ch=='M'){printf("%lld\n",ft->rsq(a,b)); }
		}
		printf("\n");
		delete(ft);
	}
	return 0;
}