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
