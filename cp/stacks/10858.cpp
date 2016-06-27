#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;


void recurse(int n,int m,std::vector<int>& factors,std::vector<std::vector<int> >& factorizations){
	for (int i = m; i*i <=n ; ++i)
	{
		if(n%i==0){
			factors.push_back(i);
			recurse(n/i,i,factors,factorizations);
			factors.pop_back();
		}
	}
	if(factors.size()){
		factorizations.push_back(factors);
		factorizations.back().push_back(n);
	}
}

int main() {
	int n;
	cin>>n;
	while(n!=0){
		std::vector<int> factors;
		std::vector<std::vector<int> > factorizations;
		recurse(n,2,factors,factorizations);
		cout<<factorizations.size()<<endl;
		for(auto f:factorizations){
			for(auto fa:f)
				cout<<fa<<" ";
			cout<<endl;
		}
		cin>>n;
	}
	return 0;
}