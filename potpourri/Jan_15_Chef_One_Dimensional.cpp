#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;
typedef pair<int,int> pi;
const int inf=1e9;
vector<int> v(2111);
int main() {
	int t;
	cin>>t;
	while(t--){
		int n;
		scanf("%d",&n);
        fill(v.begin(),v.end(),inf);
		for (int i = 0; i < n; ++i)
		{
			int a,b;
			//cin>>a>>b;
			scanf("%d%d",&a,&b);
			v[a]=min(v[a],b);
		}
		// sort(v.begin(),v.begin()+n);
		int ans=0;
		for (int i = 0; i <=2100 ; ++i)
		{
			if( v[i]==inf)
				continue;
			i=v[i];
			ans++;
		}
		//cout<<ans<<endl;
		printf("%d\n",ans );
	}
	return 0;
}