#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;
pair<long long int,long long int> pi;
std::vector<long long int> A,B;
int main() {
	long long int t;
	cin>>t;
	while(t--){
		long long int n,k;
		A.clear();
		B.clear();
		cin>>n>>k;
		for (long long int i = 0; i <n ; ++i)
		{
			long long int x;
			cin>>x;
			A.push_back(x);
		}
		for (long long int i = 0; i < n; ++i)
		{
			long long int x;
			cin>>x;
			B.push_back(x);
		}
		long long int maxim=0;
		for (long long int i = 0; i < n; ++i)
		{
			maxim=max(maxim,(k/A[i])*B[i]);
		}
		cout<<maxim<<endl;
	}
	return 0;
}