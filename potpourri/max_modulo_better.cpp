#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
using namespace std;
#define INF 10000000000
// vector<long long int>  arr(1111111);
vector<long long int> distinct;
unordered_map<long long int ,long long int >M;
// set<long long int> myset;

// long long int  bin_search(long long int left,long long int right,long long int num){
// 	long long int mid=(left+right)/2;

// 	if(left>right) return -INF;
// 	if(distinct[mid]<num){
// 		return max(distinct[mid],bin_search(mid+1,right,num));
// 	}
// 	if(distinct[mid]>=num){
// 		return bin_search(left,mid-1,num);
// 	}
// }
long long int  Maxim;
long long int  compute(long long int  n){
	long long int  max_modulo,start,i,j,temp_max;
	// std::set<long long int>::iterator it_low;
	
	max_modulo=0;
	// cout<<"M: "<<M<<endl;
	for(i=0;i<n;i++){
		start=distinct[i];
		// cout<<"Start: "<<start<<endl;
		for(j=2;j<=Maxim/start+1;++j){
			//temp_max=bin_search(i+1,n-1,j*start);
			// cout<<"temp_max: "<<temp_max<<endl;
			 // cout<<"j*start\n"<<(j*start)<<endl;
			int ind=lower_bound(distinct.begin(),distinct.end(),j*start)-distinct.begin();
			ind--;
			if(ind>=0){
				 // cout<<"Hi Inside\n";
				max_modulo=max(max_modulo,(distinct[ind])%start);
			}
		}
	}
	return max_modulo;
}

int  main(){
	long long int  i,n,res,input;
	cin>>n;
	for(i=0;i<n;i++){
		cin>>input;
		if(M[input]==0){
			M[input]=1;
			distinct.push_back(input);
			// myset.insert(arr[i]);
		}
	}
	sort(distinct.begin(), distinct.end());
	n=distinct.size();
	// cout<<"n: "<<n<<endl;
	Maxim=distinct[n-1];
	res=compute(n);
	cout<<res<<endl;
	return 0;
}