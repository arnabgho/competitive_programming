#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

#define INF 1e9

class PalindromicSubstringsDiv2 {
public:
	int count(string S,int n) {
		int i,j,k,maxim=1;
		vector<vector <bool> > DP(n+1,vector<bool> (n+1));
		for(i=0;i<n;i++) DP[i][i]=1;
		for(k=1;k<n;k++){
			for(i=0;i+k<n;i++){
				j=i+k;			
				if(k>1){
					DP[i][j]=(S[i]==S[j]) && DP[i+1][j-1];
				}
				else{
					DP[i][j]=(S[i]==S[j]);
				}
				if(DP[i][j]){
					maxim=max(maxim,j-i+1);
				}
			}
		}
		DP.clear();
		return maxim;
	}
};


int main(){

	int n,ans;
	string s;
	PalindromicSubstringsDiv2 *p;
	p=(PalindromicSubstringsDiv2 *)malloc(sizeof(PalindromicSubstringsDiv2));
	cin>>n;
	cin>>s;
	ans=p->count(s,n);
	cout<<ans<<endl;
	return 0;
}