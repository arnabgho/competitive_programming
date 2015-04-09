#include <iostream>
#include <vector>
//#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;

vector<long long int> D(100,0);
vector<long long int> A(100,0);

void compute(){
	int i,j;
	D[2]=3;
	D[0]=1;
	A[1]=1;
	A[0]=0;
	for(i=3;i<=30;i++){
		if(i%2==0){
			D[i]=D[i-2]+2*A[i-1];
		}
		else{
			A[i]=D[i-1]+A[i-2];
		}
	}
}

int main() {
	int n;
	compute();
	cin>>n;
	while(n!=-1){
		cout<<D[n]<<endl;
		cin>>n;
	}
	return 0;
}