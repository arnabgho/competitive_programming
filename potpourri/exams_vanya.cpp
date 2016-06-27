#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;
typedef long long LL;
typedef pair<LL,LL> PL;
PL temp;
vector <PL> exams; 
int main() {	
	LL i,n,r,avg,sum=0,a,b,ans=0;
	cin>>n>>r>>avg;
	for(i=0;i<n;i++){
		cin>>a>>b;
		sum+=a;
		if(a<r){
			temp=make_pair(b,a);
			exams.push_back(temp);
		}
	}
	sort(exams.begin(),exams.end());
	LL num;
	// for(i=0;i<exams.size();i++){
	// 	cout<<exams[i].second<<" "<<exams[i].first<<endl;
	// }
	i=0;
	// cout<<"Sum "<<sum<<endl;
	LL req=avg*n-sum; 
	LL pick;
	while(req>0 && i<exams.size()){
		pick=min(r-exams[i].second,req);

		num=pick;
		ans+=num*exams[i].first;
		req-=pick;
		i++;
	}
	cout<<ans<<endl;
	return 0;
}