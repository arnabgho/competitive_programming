#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;
typedef long long ll;

ll C,Hr,Hb,Wr,Wb;
const ll inf=1e9;
ll f(ll x){
	if(Wr*x>C) return -inf;
	ll y=(C-Wr*x)/Wb;
	return x*Hr+y*Hb;
}
int main() {
	
	cin>>C>>Hr>>Hb>>Wr>>Wb;
	ll mx=0;
	ll left=0;ll right=C;
	while(1){
		// cout<<"left "<<left<<" right "<<right<<endl;
		ll mid=left+(right-left)/2;
		mx=max(mx,f(mid));
		ll leftThird = left + (right - left)/3;
        ll rightThird = right - (right - left)/3;

        if (f(leftThird) < f(rightThird)){
        	if(left==leftThird) break;
            left = leftThird;
        }
        else	{
        	if(right==rightThird) break;
        	right=rightThird;
        }
	}
	cout<<mx<<endl;
	return 0;
}