#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
		int n,m,s,p,q;
		cin>>n>>m>>s>>p>>q;
		int V=1,R=1;
		int ans=0;
		int l=n-m+1;
		//cout<<"p "<<p<<" q "<<q<<endl;
		for (int i = 0; i < s; ++i)
		{
			if(V+p<m){
				V+=p;
			}
			else{
				V=(V+p)%l;
				if(V==0)
					V=n;
				else
					V+=m-1;
			}
			if(R+q<m){
				R+=q;
			}
			else{
				R=(R+q)%l;
				if(R==0)
					R=n;
				else
					R+=m-1;
			}
			//cout<<"V "<<V<<endl;
			//cout<<"R "<<R<<endl;
			if(R==V)
				ans++;
		}
		cout<<ans<<endl;
	}
	return 0;
}