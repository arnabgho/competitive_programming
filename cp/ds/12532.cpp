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
	ll n,k;
	vl num;
	while(cin>>n>>k){
		FenwickTree * ft=new FenwickTree(n);
		int isZero=0;
		num.assign(n+1,0);
		for (int i = 1; i <= n; ++i)
		{
			ll x;
			cin>>x;
			isZero+= (x==0);
			if(x!=0){
				int sgn=x/abs(x);
				num[i]=sgn;
				if(sgn<0)
					ft->adjust(i,1);
			}
		}
		string res="";
		for (int i = 0; i < k; ++i)
		{
			char ch;
			int a,b;
			cin>>ch>>a>>b;
			if(ch=='C'){
				if(b==0){
					isZero+=1;
					if(num[a]<0)
						ft->adjust(a,-1);
					num[a]=b;
				}
				else{
					if(num[a]==0)
						isZero-=1;
					int sgn=b/abs(b);
					if(sgn<0 && num[a]>0)
						ft->adjust(a,1);
					else if(sgn>0 && num[a]<0)
						ft->adjust(a,-1);
					num[a]=sgn;
				}
			}
			else if(ch=='P'){
				if(isZero) res+='0';
				else {
					int sum=ft->rsq(a,b);
					if(sum%2==0) res+="+";
					else res+="-";
				}
			}

		}
		cout<<res<<endl;
		delete(ft);
	}
	return 0;
}