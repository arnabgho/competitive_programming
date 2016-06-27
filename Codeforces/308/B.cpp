#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;
long long int numDig(long long int n){
	long long int ans=0;
	// cout<<"n "<<n<<endl;
	while(n>0){n/=10;ans++;}
	// cout<<" ans "<<ans<<endl;
	return ans;
}

long long int nDig(long long int n){
	long long int x=numDig(n);
	if(x<=1)
		return n+1;
	return 10*nDig(n/10-1)+(n/10-1)*10+(n%10+1)*x;
}

int main() {
	long long int n;
	cin>>n;
	if(n<10)
		cout<<n<<endl;
	else
		cout<<nDig(n)-1<<endl;	
	

	return 0;
}

