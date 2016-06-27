#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;

std::vector<pair<int,int> > v;
std::vector<pair<int,int> > ans;



bool pairCompare(const std::pair<int,int>& firstElem, const std::pair<int,int>& secondElem) {
	if(firstElem.first!=secondElem.first)
	  return firstElem.first < secondElem.first;
	else 
		return firstElem.second<secondElem.second;
}

void LIS(int n){
	std::vector<int> pred(n,-1);
	std::vector<pair<int,int> > max(n);
	std::vector<int> len(n);
	max[0]=v[0];
	len[0]=1;
	int maxlen=1;
	int maxpos=0;
	int i,j;
	for(i=1;i<n;i++){
		for(j=i-1;j>=0;j--){
			// cout<<"Max: "<<max[j].first<<" "<<max[j].second<<endl;
			if(max[j].first<v[i].first && max[j].second<v[i].second){
				max[i]=v[i];
				len[i]=len[j]+1;
				pred[i]=j;
				if(len[i]>maxlen){
					maxlen=len[i];
					maxpos=i;
				}
				break;
			}
		}	
		if(pred[i]==-1){
			max[i]=v[i];
			len[i]=1;
		}
	}
	int pos=maxpos;
	while(pos!=-1){
		ans.push_back(v[pos]);
		pos=pred[pos];
	}
}

int main() {
	int n,a,b,i;
	cin>>n;
	std::pair<int,int> temp;
	for(i=1;i<=n;i++){
		cin>>a>>b;
		temp=make_pair(a,b);
		v.push_back(temp);
	}
	// sort(v.begin(),v.end(),pairCompare);
	 sort(v.begin(),v.end());
	// for(i=0;i<n;i++){
	// 	cout<<v[i].first<<" "<<v[i].second<<endl;
	// }
	LIS(n);
	int len=ans.size();
	cout<<len<<endl;
	for(i=len-1;i>=0;i--){
		cout<<ans[i].first<<" "<<ans[i].second<<endl;
	}
	return 0;
}