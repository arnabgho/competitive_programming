#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;
typedef long long ll;
typedef pair<ll,ll> pi;
typedef pair<string,int> ps;
typedef pair<ps,pi> pspi;
std::map<pspi,bool> DP;
const double eps=1e-9;

set<string> S;

void recurse(string cur,int nUnclosed,int nLeft,int nRight){
	pi p=pi(nLeft,nRight);
	ps pp=ps(cur,nUnclosed);
	pspi ppp=pspi(pp,p);
	if(DP.count(ppp))
		return;
	if(nUnclosed==0 && nLeft==0 && nRight==0)
		S.insert(cur);

	if(nUnclosed>0 && nRight>0)
		recurse(cur+')',nUnclosed-1,nLeft,nRight-1);
	if(nLeft>0)
		recurse(cur+'(',nUnclosed+1,nLeft-1,nRight);

	DP[ppp]=1;
}

int main() {
	ll t;
	cin>>t;
	for (ll cas = 1; cas <= t; ++cas)
	{
		/* code */
		ll n,k;
		cin>>n>>k;
		S.clear();DP.clear();
		k--;
		recurse("",0,n,n);
		if(k>=S.size()){
			printf("Case #%lld: ",cas);
			printf("Doesn't Exist!\n");
			continue;
		}
		ll num=0;
		string ans;
		for(set<string>::iterator it=S.begin();it!=S.end();++it){
			// cout<<*it<<endl;
			if(num==k){
				ans=*it;break;
			}
			num++;
		}
		printf("Case #%lld: ",cas);
		cout<<ans<<endl;
	}
	return 0;
}