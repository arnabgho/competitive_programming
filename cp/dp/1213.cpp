#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;
std::vector<int> primes;

struct block
{
	int a,b,c;
	block(int x,int y,int z) : a(x),b(y),c(z){}
};


bool operator <(const block& x, const block& y) {
    return std::tie(x.a, x.b, x.c) < std::tie(y.a, y.b, y.c);
}

map<block,int> DP;

void sieve(int n){
	std::vector<bool> v(n+1,1);
	v[1]=0;
	v[0]=0;
	for (int i = 2; i <=n ; ++i)
	{
		if(v[i]){
			for (int j = i*i; j <=n ; j+=i)
			{
				v[j]=0;
			}
		}
	}
	for (int i = 0; i <=n ; ++i)
	{
		if(v[i])
			primes.push_back(i);
	}
}

int recurse(int i,int j,int k){
	if(DP.find(block(i,j,k))!=DP.end())
		return DP[block(i,j,k)];
	if(i==0 && (k)!=0) return 0;
	if(j==0 && (i+k)!=0) return 0;
	if(k==0 && (i)!=0) return 0;
	int val=recurse(i,j-1,k);
	if(i>=primes[j-1])
		val+=recurse(i-primes[j-1],j-1,k-1);
	return DP[block(i,j,k)]=val;
}


int main() {
	std::clock_t start;
    double duration;

    start = std::clock();
	int n,k;
	sieve(1132);
	DP[block(0,0,0)]=1;
	int numPrimes=primes.size();
	cin>>n>>k;
	while(n+k>0){
		cout<<recurse(n,numPrimes,k)<<endl;
		cin>>n>>k;
	}
	duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;

    // std::cout<<"time required "<< duration <<'\n';
	return 0;
}