#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;

std::vector<int> v1,v2,away,home;
int main() {
	int i,j,n,a,b;
	cin>>n;
	for(i=0;i<n;i++){
		cin>>a>>b;
		v1.push_back(a);
		v2.push_back(b);
		away.push_back(0);
		home.push_back(n-1);	
	}
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(j==i) continue;
			if(v1[i]==v2[j]){
				home[j]++;
			}
			else {away[j]++;}
		}
	}
	for(i=0;i<n;i++){
		cout<<home[i]<<" "<<away[i]<<endl;
	}
	return 0;
}