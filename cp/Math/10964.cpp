#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;
typedef long long ll;
typedef pair<ll,ll> pi;

pi getCoord(ll k){
	if(k==0)
		return pi(0,0);
	ll lo=0;
	ll hi=1e6;
	ll n=0;
	while(lo<hi){
		ll mid=lo + (hi-lo)/2;
		if(2*mid*(mid+1)<=k){
			n=max(n,mid);
			lo=mid+1;
		}
		else{
			hi=mid;
		}
	}
	// cout<<"k "<<k<<" n "<<n<<endl;
	ll position=k-2*n*(n+1);
	// cout<<"position "<<position<<endl;
	pi cur=pi(-n,1);
	ll sum=n+1;
	while(position>1){
		if(cur.first<0 && cur.second>=0)
			cur=pi(cur.first+1,cur.second+1);
		else if(cur.first>=0 && cur.second>0)
			cur=pi(cur.first+1,cur.second-1);
		else if(cur.first>0 && cur.second<=0)
			cur=pi(cur.first-1,cur.second-1);
		else if(cur.first<=0 && cur.second<0)
			cur=pi(cur.first-1,cur.second+1);
		position--;
	}
	return cur;
}

int main() {
	ll a,b;
	cin>>a>>b;
	while(a+b!=-2){
		pi x,y;
		x=getCoord(a);
		y=getCoord(b);
		// cout<<"x "<<x.first<<" "<<x.second<<endl;
		// cout<<"y "<<y.first<<" "<<y.second<<endl;
		double sq=(x.first-y.first)*(x.first-y.first) + (x.second-y.second)*(x.second-y.second);
		// cout<<"sq "<<sq<<endl;
		double res=sqrt(sq);
		printf("%.2lf\n",res);
		cin>>a>>b;
	}
	return 0;
}