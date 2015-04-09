#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;

int h[1100];
int w[1100];
int main() {
	int ans=1e9;
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>w[i]>>h[i];
	}

	for(int H=1;H<=1000;H++){
		std::vector<int> decrease;
		int width=0;
		bool pos=1;
		int k=0;
		for(int i=0;i<n;i++){
			if(h[i]>=w[i]){
				if(h[i]<=H)
					width+=w[i];
				else{
					if(w[i]<=H){
						width+=h[i];
						k++;
					}
					else{
						pos=0;break;
					}
				}
			}
			else{
				if(w[i]>H && h[i]<=H){
					width+=w[i];
				}
				else if(w[i]<=H && h[i]<=H){
					width+=w[i];
					decrease.push_back(w[i]-h[i]);
				}
				else{
					pos=0;break;
				}
			}
		}
		sort(decrease.rbegin(),decrease.rend());
		if(pos){
			if(k>n/2)
				continue;
			int i=0;
			while(k+1<=n/2 && i<decrease.size()){
				k++;
				width-=decrease[i++];
			}
			ans=min(ans,width*H);
		}
	}
	cout<<ans<<endl;
	return 0;
}