#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;
typedef pair<int,int> pi;

struct CompareByPosition {
    bool operator()(const pi &lhs, const pi &rhs) {
        if (lhs.first != rhs.first) 
            return lhs.first < rhs.first;
        return lhs.second > rhs.second;
    }
};

set <pi> Forward;
set <pi,CompareByPosition> backward;

int main() {
	int t;
	cin>>t;
	while(t--){
		Forward.clear();
		backward.clear();
		int n,m;
		cin>>n>>m;
		for (int i = 1; i <= n; ++i)
		{
			Forward.insert(pi(0,i));
			backward.insert(pi(0,i));
		}
		pi ans=pi(0,0);
		for (int i = 1; i <= m; i++)
		{
			pi p;
			if(i%2==1){
				p=*Forward.begin();
				Forward.erase(Forward.begin());
				Forward.insert(pi(p.first+1,p.second));
				backward.erase(backward.find(p));
				backward.insert(pi(p.first+1,p.second));
			}
			else{
				p=*backward.begin();
				backward.erase(backward.begin());
				backward.insert(pi(p.first+1,p.second));
				Forward.erase(Forward.find(p));
				Forward.insert(pi(p.first+1,p.second));
			}	
			if(i==m){
				ans.first=p.second;
				ans.second=p.first;
			}
		}
		cout<<ans.first<<" "<<ans.second<<endl;
	}
	return 0;
}