#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;
std::vector<int> v;
int main() {
	set<int> M;
	int n,k,a,m;
	cin>>n>>k>>a;
	cin>>m;
	for (int i = 0; i <m ; ++i)
	{
		int x;cin>>x;v.push_back(x);
	}
	M.insert(0);M.insert(n+1);
	bool pos=1;
	int ans=-1;
	int num=(n+1)/(a+1);
	for (int i = 0; i < m && pos; ++i)
	{
		// cout<<"------------\n";
		// cout<<"num init "<<num<<endl;
		set<int>::iterator it;
		int left,right;
		it=M.upper_bound(v[i]);
		it--;
		left=*it;
		it=M.lower_bound(v[i]+1);
		right=*it;
		num-=(right-left)/(a+1);
		num+=(v[i]-left)/(a+1)+(right-v[i])/(a+1);
		M.insert(v[i]);
		// cout<<"v[i] "<<v[i]<<" left "<<left<<" right "<<right<<" num "<<num<<endl; 
		if(num<k){
			pos=0;
			ans=i+1;
		}
	}
	
	cout<<ans<<endl;
	return 0;
}