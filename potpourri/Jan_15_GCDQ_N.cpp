#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;
vector<int> gcd_left(111111);
vector<int> gcd_right(111111);
int v[111111];

int gcd(int a,int b){
	if(b==0)
		return a;
	else return gcd(b,a%b);
}

void precompute(int n){
	gcd_left[0]=v[0];
	for (int i = 1; i <n ; ++i)
	{
		gcd_left[i]=gcd(gcd_left[i-1],v[i]);
	}
	gcd_right[n-1]=v[n-1];
	for (int i = n-2; i >=0 ; --i)
	{
		gcd_right[i]=gcd(gcd_right[i+1],v[i]);
	}
}
int main() {
	int t;
	cin>>t;
	while(t--){
		int n,q;
		cin>>n>>q;
		for (int i = 0; i < n; ++i)
		{
			scanf("%d",&v[i]);
		}
		precompute(n);
		for (int i = 0; i < q; ++i)
		{
			int l,r,res;
			// cin>>l>>r;
			scanf("%d%d",&l,&r);
			l--;r--;
			if(l==0){
				res=gcd_right[r+1];
			}
			else if(r==n-1){
				res=gcd_left[l-1];
			}
			else{
				res=gcd(gcd_left[l-1],gcd_right[r+1]);
			}
			//cout<<res<<endl;
			printf("%d\n",res );
		}
	}
	return 0;
}