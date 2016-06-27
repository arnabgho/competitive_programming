#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

#define INF 1e9
using namespace std;
std::vector<int> pos(1111);
int main() {
	int i,n,start=0,end;
	double maxim;
	cin>>n;
	cin>>end;
	for(i=0;i<n;i++){
		cin>>pos[i];
	}
	sort(pos.begin(), pos.begin()+n);
	maxim=-INF;
	maxim=max(pos[0],end-pos[n-1]);
	for(i=1;i<n;i++){
		maxim=max(maxim,(pos[i]-pos[i-1])/2.0);
	}
	std::cout << std::fixed << std::showpoint;
	std::cout << std::setprecision(9);
	cout<<maxim<<endl;
	return 0;
}