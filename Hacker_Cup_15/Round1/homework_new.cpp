#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;
std::vector<bool> prime(11111111,true);
std::vector<int> numPrimeFactor(11111111,0);

void sieve(){
	for (int i = 2; i*i <=10000000 ; ++i)
	{
		if(!prime[i])
			continue;
		 numPrimeFactor[i]=1;
		for (int j = 2*i; j <=10000000 ; j+=i)
		{
			prime[j]=false;
			numPrimeFactor[j]++;
		}
	}
}

// void precompute(){
// 	for (int N = 2; N <=10000000 ; ++N)
// 	{
// 		if(prime[N]){
// 			numPrimeFactor[N]=1;continue;
// 		}

// 		int x=N;
// 		int nP=0;
// 		for (int i =2; i*i <=N ; ++i)
// 		{
// 			if(x%i==0){
// 				nP++;
// 				while(x%i==0){
// 					x/=i;
// 				}
// 				nP+=numPrimeFactor[x];
// 				break;
// 			}
// 		}
// 		numPrimeFactor[N]=nP;
// 		// cout<<" N "<<N<<" nP "<<nP<<endl;
//  	}
// }
int main() {
	int t;
	sieve();
	// precompute();
	cin>>t;
	for(int cas=1;cas<=t;cas++){
		int A,B,K,ans=0;
		cin>>A>>B>>K;

		for (int i = A; i <=B ; ++i)
		{
			if(numPrimeFactor[i]==K)
				ans++;
		}
		cout<<"Case #"<<cas<<": "<<ans<<endl;
		// cout<<ans<<endl;
	}
	return 0;
}