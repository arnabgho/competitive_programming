#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;
std::vector<int> a;
int n, k, p, x , y;
bool getMedian(){
	int num=a.size();
	if(num==0) return 0;
	sort(a.begin(), a.end());
	if(num%2==1)
		return a[n/2]>=y;
	double p=a[n/2];
	double q=a[n/2-1];
	return (p+q)/2.0>=y;
}
int main() {
	
	cin>>n>>k>>p>>x>>y;
	int sum=0;
	for (int i = 0; i < k; ++i)
	{
		int p;
		cin>>p;
		a.push_back(p);
		sum+=p;
	}
	int rem=x-sum;
	bool pos=1;
	std::vector<int> vRem;
	for (int i = 0; i < n-k && pos; ++i)
	{
		if(getMedian()){
			if(rem>=1){
				a.push_back(1);
				vRem.push_back(1);
				rem-=1;
			}
			else pos=0;
		}
		else{
			if(rem>=y){
				a.push_back(y);
				vRem.push_back(y);
				rem-=y;
			}
			else pos=0;
		}
	}
	if(!pos) cout<<"-1\n";
	else {
		for (int i = 0; i < vRem.size(); ++i)
		{
			cout<<vRem[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}