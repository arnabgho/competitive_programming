#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;

int main() {
	int n,m;	
	cin>>n>>m;
	vector<int> minStep(20001,-1);
	queue<int> q;
	q.push(n);
	minStep[n]=0;
	while(!q.empty()){
		int cur=q.front();
		q.pop();
		// cout<<"cur "<<cur<<endl;
		if(cur==m){
			cout<<minStep[m]<<endl;
			return 0;
		}
		// cout<<"2*cur "<<2*cur<<" minStep "<<minStep[2*cur]<<endl;
		if( cur<=10000 && minStep[2*cur]==-1){
			// cout<<"Hi1 \n";
			minStep[2*cur]=minStep[cur]+1;
			q.push(2*cur);
		}
		// cout<<"cur-1 "<<cur-1<<" minStep "<<minStep[cur-1]<<endl;
		if(cur>1 && minStep[cur-1]==-1){
			// cout<<"Hi2 \n";
			minStep[cur-1]=minStep[cur]+1;
			q.push(cur-1);
		}
	}
	return 0;
}