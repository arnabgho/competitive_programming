#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;

int main() {
	int n;
	cin>>n;
	while(n!=0){
		std::vector<int> v;
		for (int i = 0; i < n; ++i){int x;cin>>x;v.push_back(x);}
		int sum=0;
		int best=-1;
		for (int i = 0; i < n; ++i){
			sum+=v[i];
			best=max(sum,best);
			if(sum<0)
				sum=0;
		}	
		if(best>0)
			cout<<"The maximum winning streak is "<<best<<".\n";
		else
			cout<<"Losing streak.\n";
		cin>>n;
	}
	return 0;
}