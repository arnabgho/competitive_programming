#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;
typedef long long ll;
typedef pair<ll,ll> pi;
int main() {
	ll m,n;
	cin>>m>>n;
	while(!(n==1 && m==1) ){
		
		pi left=pi(0,1);
		pi right=pi(1,0);
		pi lim_left=pi(0,1);
		pi lim_right=pi(1,0);
		string res="";
		while(1){
			pi mid=pi(left.first+right.first,left.second+right.second);
			if(mid==pi(m,n))
				break;
			if(m*mid.second>n*mid.first){
				left=mid;
				res+="R";
			}
			else{
				right=mid;
				res+="L";
			}
		}
		cout<<res<<endl;
		cin>>m>>n;
	}
	return 0;
}