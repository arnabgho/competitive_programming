#include <stdio.h>
#include <iostream>

using namespace std;

long long int res[100001];
long long int cum[100001];
#define NUM 1000000007 
void compute(long long int k){
	long long int i;
	res[0]=1;
	for(i=1;i<=100000;i++){
		if(i<k)
			res[i]=1;
		else{
			res[i]=(res[i-k]+res[i-1])%NUM;
		}
	}
}

void cumsum(){
	for(int i=1;i<=100000;i++)
		cum[i]=(cum[i-1]+res[i]);
}

int main()
{
	long long int t,k,i,a,b;
	cin>>t>>k;	

	compute(k);
	cumsum();
	for(i=1;i<=t;i++){
		cin>>a>>b;
		cout<<(cum[b]-cum[a-1])%NUM<<endl;
	}
	return 0;
}