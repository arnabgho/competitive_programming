#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;
deque<int> Wash;
deque<int> Dry;
deque<int> Folder;
int TIME[11111];
int main() {
	int i,j,k,n1,n2,n3,t1,t2,t3;
	cin>>k>>n1>>n2>>n3>>t1>>t2>>t3;
	for(i=0;i<n1;i++)
		Wash.push_back(0);
	for(i=0;i<n2;i++)
		Dry.push_back(0);
	for (int i = 0; i < n3; ++i)
		Folder.push_back(0);

	for(i=1;i<=k;i++){
		int earliest_wash=Wash.back();
		int earliest_dry=Dry.back();
		int earliest_fold=Folder.back();
		int earliest_start=max(earliest_fold-t1-t2,max(earliest_wash,earliest_dry-t1));
		int earliest_finish=earliest_start+t1+t2+t3;
		Wash.pop_back();Dry.pop_back();Folder.pop_back();
		Wash.push_front(earliest_start+t1);Dry.push_front(earliest_start+t1+t2);Folder.push_front(earliest_start+t1+t2+t3);
		TIME[i]=earliest_finish;
	}
	cout<<TIME[k]<<endl;
	return 0;	
}