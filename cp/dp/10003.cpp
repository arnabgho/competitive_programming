#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;
std::vector<int> cuts;
int l,n;
typedef pair<int,int> pi;
std::map<pi, int> DP;

int recurse(pi stick){
	if(DP.count(stick))
		return DP[stick];
	int minim=1e9;
	int len=cuts[stick.second]-cuts[stick.first];
	for(int i=stick.first+1;i<stick.second;i++){
		minim=min(minim,len+recurse(pi(stick.first,i))+recurse(pi(i,stick.second)));
	}
	DP[stick]= (minim==1e9) ? 0:minim;
	return DP[stick];
}

int main() {
	cin>>l;
	while(l>0){
		cin>>n;
		cuts.clear();
		DP.clear();
		cuts.push_back(0);
		for (int i = 0; i <n ; ++i)
		{
			int x;cin>>x;
			cuts.push_back(x);
		}
		cuts.push_back(l);
		printf("The minimum cutting is %d.\n",recurse(pi(0,n+1)) );
		cin>>l;
	}
	return 0;
}
