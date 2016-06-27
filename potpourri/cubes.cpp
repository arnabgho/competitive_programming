#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;

int main() {
	int n,i,k;
	cin>>n;
	i=1;
	while(1){
		k=(i*(i+1)*(i+2));
		k/=6;
		if(k<=n){
			i++;
		}
		else break;
	}
	cout<<i-1<<endl;
	return 0;
}