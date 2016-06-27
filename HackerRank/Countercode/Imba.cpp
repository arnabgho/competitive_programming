#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int left=1,right=n;
		std::vector<int> res;
		while(left<=right){
			if(left==right){
				res.push_back(left);break;
			}
			res.push_back(right--);res.push_back(left++);
		}
		reverse(res.begin(),res.end());
		for(auto x:res) cout<<x<<" ";
		cout<<endl;	
	}
	return 0;
}