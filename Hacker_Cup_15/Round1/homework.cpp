#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;

std::vector<int> numPrimeFactor(11111111,0);

void precompute(){
	for (int N = 2; N <=10000000 ; ++N)
	{
		int x=N;
		int nP=0;
		for (int i =2; i*i <=N ; ++i)
		{
			if(x%i==0){
				nP++;
			}
			while(x%i==0){
				x/=i;
			}
		}
		if(x>1)
			nP++;
		numPrimeFactor[N]=nP;
		cout<<" N "<<N<<" nP "<<nP<<endl;
 	}
}
int main() {
	int t;
	precompute();
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