#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;
 
typedef long long int LL;
LL Ncr[300][300];
LL MOD=1e9+7LL;
void compute(){
	int i,j;
	for(i=0;i<=200;i++){
		Ncr[i][0]=1;
	}
	for(j=1;j<=200;j++){
		Ncr[0][j]=0;
	}
	for(i=1;i<=200;i++){
		for(j=1;j<=i;j++){
			Ncr[i][j]=(Ncr[i-1][j-1]+Ncr[i-1][j])%MOD;
		}
	}
}

int main() {
	LL t,m,n;
	compute();
	cin>>t;
	while(t--){
		cin>>m>>n;
		cout<<Ncr[m+n][n]<<endl;		
	}
	return 0;
}