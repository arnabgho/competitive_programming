#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;
typedef pair<int,int> pi;
std::vector<pi> E;
int main() {
	int n;
	char ch;
	int num;
	cin>>n;
	for (int i = 0; i < n; ++i)
	{
		// scanf("%c %d\n",&ch,&num);
		cin>>ch>>num;
		// cout<<"ch "<<ch<<" num "<<num<<endl;
		if(ch=='+')
			E.push_back(pi(1,num));
		else
			E.push_back(pi(-1,num));
	}
	// for (int i = 0; i < n; ++i)
	// {
	// 	cout<<E[i].first<<" "<<E[i].second<<endl;
	// }

	for (int initial = 0; initial <=5000 ; ++initial)
	{
		bool pos=1;
		set<int> DP;
		int cur=initial;
		int ans=initial;
		for (int i = 0; i <n && pos; ++i)
		{
			int status=E[i].first;
			int reg=E[i].second;
			if(status==1){
				cur++;
				DP.insert(reg);
				ans=max(cur,ans);
			}
			else{
				if(DP.count(reg)){
					DP.erase(DP.find(reg));
				}
				cur--;
				ans=max(cur,ans);
			}
			if(cur<0 || (cur==0 && DP.size()!=0))
				pos=0;
		}
		if(pos){
			cout<<ans<<endl;
			break;
		}
	}
	return 0;
}