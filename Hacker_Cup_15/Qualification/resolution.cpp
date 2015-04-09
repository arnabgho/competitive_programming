#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

typedef long long ll;
using namespace std;
std::vector<int> P(30);
std::vector<int> C(30);
std::vector<int> F(30);

bool getBit(int n,int i){
	return (n&(1<<i))!=0;
}

int main() {
	int t;
	cin>>t;
	for (int cas = 1; cas <=t ; ++cas)
	{
		int n;
		ll GP,GC,GF;
		cin>>GP>>GC>>GF;
		cin>>n;		
		for (int i = 0; i < n; ++i)
		{
			cin>>P[i]>>C[i]>>F[i];
		}
		bool found=false;
		for(ll bitmask=0;bitmask<1<<n && !found;bitmask++){
			int cP=0,cC=0,cF=0;
			for(int i=0;i<n;i++){
				if(getBit(bitmask,i)){
					cP+=P[i];
					cC+=C[i];
					cF+=F[i];
				}
			}
			if(cP==GP && cC==GC && cF==GF)
				found=true;
		}
		string res="yes";
		if (!found)
			res="no";

		cout<<"Case #"<<cas<<": "<<res<<endl;	
	}
	return 0;
}