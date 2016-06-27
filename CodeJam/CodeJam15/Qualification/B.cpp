#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;
int main() {
	int te;
	cin>>te;
	for (int cas = 1; cas <=te ; ++cas)
	{
		int d;
		cin>>d;
		std::vector<int> P(1100,0);
		for (int i = 0; i < d; ++i)
		{
			int x;
			cin>>x;
			P[x]++;
		}
		int t=0;
		while(d>0){
			int mx=-1;
			int mx2=-1;
			for(int i=1000;i>0;i--){
				if(P[i]>1 && mx==-1){ mx=i;mx2=i;}
				else if(P[i]==1 && mx==-1){mx=i;}
				else if(P[i]>0 && mx!=-1 && mx2==-1) mx2=i;
			}
			// cout<<"mx "<<mx<<endl;
			// cout<<"mx2 "<<mx2<<endl;
			if(mx-1>=max(max(mx/2,mx-mx/2),mx2)){
				P[mx]--;
				P[mx/2]++;
				P[mx-mx/2]++;
			}
			else{
				for (int i = 1; i <=1000 ; ++i)
				{
					if(P[i]>0){
						P[i-1]=P[i];
						P[i]=0;
					}
				}
			}
			d=0;
			for(int i=1000;i>0;i--){
				// if(P[i]>0) cout<<"pos i "<<i<<endl;
				d+=(P[i]>0);
			}

			t++;
		}
		cout<<"Case #"<<cas<<": "<<t<<endl;
	}
	return 0;
}