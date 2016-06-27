#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;
std::vector<int> v(111111);
std::map<int, int> mymap;
int main() {
	int i,t,count,c,count1,n,min,max;
	cin >>t;
	while(t--){
		cin>>n;
		for (i = 0; i < n; ++i)
		{
			cin>>v[i];
			mymap[v[i]]++;
		}
		sort(v.begin(),v.begin()+n);
		int ans=0;
		max=v[n-1];
		min=v[0];
		i=n-1;
		// cout<<"min "<<min<<" max "<<max<<endl;
		while(i>0){
			if(v[i]==min) break;
			max=v[i];
			while(v[i]==max && i>0){
				i--;
			}
			count=mymap[max];
			count1=mymap[v[i]];
			// cout<<"max "<<max<<" count "<<count<<endl;
			// cout<<"v[i] "<<v[i]<<" count1 "<<count1<<endl;
			if(count1>1){
				mymap[min]+=count;
			}
			else{
				mymap[v[i]]++;
				mymap[min]+=count-1;
			}
			ans++;
		}
		ans++;
		cout<<ans<<endl;
		v.clear();
		mymap.clear();
	}
	return 0;
}