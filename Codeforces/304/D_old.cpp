#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;

vector<int> A(5001000);
vector<int> F(5001000);
vector<bool> primes(5001000,1);
std::vector<int> allprimes;

void getPrimes(){
	for (int i = 2; i*i <=5001000 ; ++i)
	{
		if(primes[i]){
			for (int j = i*i; j <=5001000 ; j+=i)
			{
				primes[j]=0;
			}
		}
	}
}

int factors(int n){
	if(primes[n]) return 1;
	int ans=0;
	for (int i = 0; i <allprimes.size() ; ++i)
	{
		if(n%allprimes[i]==0)
			return F[n/allprimes[i]]+1;
	}
}

void preprocess(){
	for (int i = 2; i <=5001000 ; ++i)
	{
		if(primes[i]) allprimes.push_back(i);
	}
	A[1]=0;

	for (int i = 2; i <=5001000 ; ++i)
	{
		F[i]=factors(i);
		A[i]=A[i-1]+F[i];
	}
}

int main() {
	int t;
	cin>>t;
	getPrimes();
	preprocess();

	// cout<<"Primes------\n";
	// for (int i = 0; i < 10; ++i)
	// {
	// 	cout<<allprimes[i]<<endl;
	// }
	// cout<<"--------\n";	
	for (int i = 0; i < t; ++i)
	{
		int a,b;
		// cin>>a>>b;
		// cout<<A[a]-A[b]<<endl;
		scanf("%d%d",&a,&b);
		printf("%d\n",A[a]-A[b] );
	}
	return 0;
}