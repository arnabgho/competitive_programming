#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;

std::vector<int> v1,v2,away,home;
int away_arr[111111];
int home_arr[111111];
int main() {
	int i,j,n,a,b;
	cin>>n;
	for(i=0;i<n;i++){
		cin>>a>>b;
		v1.push_back(a);
		v2.push_back(b);
		away.push_back(n-1);
		home.push_back(n-1);	
		away_arr[b]++;
		home_arr[a]++;
	}
	for(i=0;i<n;i++){
		b=v2[i];
		away[i]-=home_arr[b];
		home[i]=2*(n-1)-away[i];
	}
	for(i=0;i<n;i++){
		cout<<home[i]<<" "<<away[i]<<endl;
	}
	return 0;
}