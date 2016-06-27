#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;

int main() {
	int b;
	cin>>b;
	for (int r = 1; r <= b; ++r)
	{
		int n;
		cin>>n;
		std::vector<int> v;
		for (int i = 0; i < n-1; ++i)
		{
			int x;
			cin>>x;
			v.push_back(x);
		}
		int sum=0;
		int cur_st=1;
		int best=-1;
		int best_st=-1;
		int best_en=-1;
		for (int i = 0; i < n-1; ++i)
		{
			sum+=v[i];
			if(sum>=best){
				best=max(sum,best);
				best_en=i+2;
				best_st=cur_st;
			}
			if(sum<0){
				sum=0;
				cur_st=i+2;
			}
		}
		if(best<0){
			cout<<"Route "<<r<<" has no nice parts\n";
		}
		else{
			cout<<"The nicest part of route "<<r<<" is between stops "<<best_st<<" and "<<best_en<<endl;
		}
	}
	return 0;
}