#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;
std::vector<int> coord;
std::vector<int> x(2);
std::vector<int> y(2);
int main() {

	int n,i,j,num;
	cin>>n;
	for (i = 0; i < n; ++i)
	{
		cin>>num;
		coord.push_back(num);
	}
	bool pos=1;
	for (i = 0; i < n-1 && pos; i++)
	{
		x[0]=coord[i];x[1]=coord[i+1];sort(x.begin(),x.end());
		for(j=0;j<n-1 && pos;j++){
			if(i==j) continue;
			y[0]=coord[j];y[1]=coord[j+1];sort(y.begin(),y.end());
			if((x[0]<y[1] && x[0]>y[0]) && (x[1]>y[1])){
				// cout<<"x "<<x[0]<<" "<<x[1]<<endl;
				// cout<<"y "<<y[0]<<" "<<y[1]<<endl;
				pos=0;
			}
			else if((x[1]<y[1] && x[1]>y[0]) && (x[0]<y[0])){
				// cout<<"x "<<x[0]<<" "<<x[1]<<endl;
				// cout<<"y "<<y[0]<<" "<<y[1]<<endl;
				pos=0;
			}
		}
	}
	if(!pos) cout<<"yes\n";
	else cout<<"no\n";
	return 0;
}