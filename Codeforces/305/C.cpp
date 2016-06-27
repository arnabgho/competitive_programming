#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;
typedef long long ll;
std::vector<ll> cycle1;
std::vector<ll> cycle2;
map<ll,ll> DP1;
std::map<ll, ll> DP2;
int main() {
	ll m,h1,a1,x1,y1,h2,a2,x2,y2;
	cin>>m;
	cin>>h1>>a1;
	cin>>x1>>y1;
	cin>>h2>>a2;
	cin>>x2>>y2;
	DP1[h1]=0;
	bool f=0;
	ll p=h1;
	ll i=1;
	while(!f){
		p=(x1*p+y1)%m;
		if(DP1.find(p)!=DP1.end()){
			f=1;
			cycle1.push_back(p);
			break;
		}
		DP1[p]=i;
		i++;
	}
	while( (x1*p+y1)%m!=cycle1[0] ){
		p=(x1*p+y1)%m;
		cycle1.push_back(p);
	}

	f=0;
	p=h2;
	i=1;

	while(!f){
		p=(x2*p+y2)%m;
		if(DP2.find(p)!=DP2.end()){
			f=1;
			cycle2.push_back(p);
			break;
		}
		DP2[p]=i;
		i++;
	}
	while( (x2*p+y2)%m!=cycle2[0] ){
		p=(x2*p+y2)%m;
		cycle2.push_back(p);
	}
	if(DP1.find(a1)==DP1.end() || DP2.find(a2)==DP2.end()){
		cout<<"-1\n";return 0;
	}

	ll pos1=DP1[a1];
	ll pos2=DP2[a2];
	ll len1=cycle1.size();
	ll len2=cycle2.size();
	ll t1=pos1;
	ll t2=pos2;
	while(t1!=t2 && t1<=1e8){
		if(t1>t2){
			t1+=len1;
		}
		else{
			t2+=len2;
		}
	}
	if(t1==t2)
		cout<<t1<<endl;
	else
		cout<<"-1\n";
	return 0;
}