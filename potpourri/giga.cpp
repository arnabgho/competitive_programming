#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;

typedef long long LL;
bool contains8(LL a){
	while(a>0){
		if(a%10==8) return true;
		a/=10;
	}
	return false;
}

LL mod(LL x){return x>0 ? x:-x;}
int main() {
	long long int n,left,right;
	cin>>n;
	bool found=0;
	left=n+1;
	while(!found){
		if(contains8(mod(left))){cout<<left-n<<endl;break;}
		left++;
	}

	return 0;
}