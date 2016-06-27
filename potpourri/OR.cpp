#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
using namespace std;
#define INF 10000000000
typedef std::vector<int> VI;

std::vector<VI> B(111);
std::vector<VI> A(111);
// std::vector<VI> RB(111);
std::vector<int> Row;
std::vector<int> Col;


int main(){

	int m,n,i,j,num,ans;
	cin>>m>>n;
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			cin>>num;
			B[i].push_back(num);
			A[i].push_back(1);
		}
	}
	// cout<<"Hi1\n";
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			if(B[i][j]==0){
				fill(A[i].begin(), A[i].end(),0);
				for(int k=0;k<m;k++) A[k][j]=0;
			}
		}
	}
	// cout<<"Hi2\n";
	for(i=0;i<m;i++){
		ans=0;
		for(j=0;j<n;j++){
			ans=ans||A[i][j];
		}
		Row.push_back(ans);
	}
	// cout<<"Hi3\n";
	for(j=0;j<n;j++){
		ans=0;
		for(i=0;i<m;i++){
			ans=ans||A[i][j];
		}
		Col.push_back(ans);
	}
	// cout<<"Hi4\n";
	int pos=1;
	int temp;
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			temp=Row[i]||Col[j];
			if(temp!=B[i][j]){
				pos=0;
				break;
			}
		}
	}
	if(!pos) cout<<"NO\n";
	else{
		cout<<"YES\n";
		for(i=0;i<m;i++){
			for(j=0;j<n;j++){
				cout<<A[i][j]<<" ";
			}
			cout<<endl;
		}
	}

	return 0;
}	