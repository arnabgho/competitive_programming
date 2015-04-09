#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;
typedef long long LL;
LL recursive_power(LL a,LL b){
	if(a==0)
		return (2%b);
	else{
		LL ans=recursive_power(a-1,b);
		return (ans*ans)%b;
	}
}

LL iter_power(LL a,LL b){
	LL val=2;
	for (int i = 0; i < a; ++i)
	{
		val=(val*val)%b;
	}
	return val;
}
int main(){
	LL a,b,ans;
	cin>>a>>b;
	ans=iter_power(a,b);
	cout<<ans<<endl;
	return 0;
}