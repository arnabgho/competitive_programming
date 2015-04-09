#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;
typedef long long int LL;

std::vector<LL> D(11111);
std::vector<LL> RightMax(11111);
std::vector<LL> LeftMin(11111);
std::vector<LL> LeftMax(11111);
std::vector<LL> RightMin(11111);
LL n;
void refresh(){
	std::fill (D.begin(),D.begin()+n,0);
	std::fill (RightMax.begin(),RightMax.begin()+n,0);
	std::fill (LeftMin.begin(),LeftMin.begin()+n,0);
	std::fill (LeftMax.begin(),LeftMax.begin()+n,0);
	std::fill (RightMin.begin(),RightMin.begin()+n,0);
}

#define INF 1e14
int main() {
	LL t,i,maxim,temp_max;
	cin>>t;
	while(t--){
		cin>>n;
		for(i=0;i<n;i++){
			cin>>D[i];
		}

		LeftMax[0]=D[0];
		LeftMin[0]=D[0];
		for(i=1;i<n;i++){
			LeftMin[i]=min(D[i],LeftMin[i-1]+D[i]);
			LeftMax[i]=max(D[i],LeftMax[i-1]+D[i]);
		}
		RightMin[n-1]=D[n-1];
		RightMax[n-1]=D[n-1];
		for(i=n-2;i>=0;i--){
			RightMax[i]=max(D[i],RightMax[i+1]+D[i]);
			RightMin[i]=min(D[i],RightMin[i+1]+D[i]);
		}
		maxim=-INF;
		for(i=0;i<n-1;i++){
			temp_max=max( abs(LeftMin[i]-RightMax[i+1]),abs(LeftMax[i]-RightMin[i+1])  );
			maxim=max(maxim,temp_max);
		}
		cout<<maxim<<endl;
		refresh();
	}

	return 0;
}