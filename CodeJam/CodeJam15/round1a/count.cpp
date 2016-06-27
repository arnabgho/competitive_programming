#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;



int countBits(int n){
    int ans=0;
    // cout<<"n "<<n<<endl;
    while(n>0){
        ans+=n%2;
        n/=2;
    }
    // cout<<"numBits "<<ans<<endl;
    return ans;
}

int main() {
	while(1){
		int n;
		cin>>n;
		cout<<countBits(n)<<endl;
		int ch;
		cin>>ch;
		if(ch==0) break;
	}
	return 0;
}