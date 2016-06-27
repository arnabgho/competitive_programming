#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;

int main() {
	int n,q,cas=1;
	cin>>n>>q;
	while(!(n==0 && q==0)){
		std::vector<int> v;
		for (int i = 0; i < n; ++i)
		{
			int x;cin>>x;v.push_back(x);
		}
		sort(v.begin(),v.end());
		std::vector<int>::iterator it;
		printf("CASE# %d:\n",cas);
		for (int i = 0; i < q; ++i)
		{
			int x;cin>>x;
			it=lower_bound(v.begin(),v.end(),x);
			int pos=it-v.begin();
			if(v[pos]==x)
				printf("%d found at %d\n",x,pos+1);
			else
				printf("%d not found\n",x );
		}
		cin>>n>>q;
		cas++;
	}
	return 0;
}