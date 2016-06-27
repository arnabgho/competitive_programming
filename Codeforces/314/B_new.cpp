#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;
std::vector<bool> v(1111111,0);
int main() {
	int n;
	int ans=0;
	int cur=0;
	char ch;
	int num;
	cin>>n;
	for (int i = 0; i < n; ++i)
	{
		cin>>ch>>num;
		if(ch=='+'){
			v[num]=1;
			cur++;
		}
		else{
			if(v[num]==0){
				ans++;
			}
			else{
				cur--;
				v[num]=0;
			}
		}
		ans=max(ans,cur);
	}
	cout<<ans<<endl;
	return 0;
}