#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <unordered_map>
using namespace std;
#define INF 10000000000
vector<long long int>  arr(1111111);
vector<long long int> distinct;
unordered_map<long long int ,long long int >M;

long long int  bin_search(long long int left,long long int right,long long int num){
	long long int mid=(left+right)/2;

	if(left>right) return -INF;
	if(distinct[mid]<num){
		return max(distinct[mid],bin_search(mid+1,right,num));
	}
	if(distinct[mid]>=num){
		return bin_search(left,mid-1,num);
	}
}

long long int  compute(long long int  n){
	long long int  M,max_modulo,start,i,j,temp_max;
	M=distinct[n-1];
	max_modulo=0;
	// cout<<"M: "<<M<<endl;
	for(i=0;i<n;i++){
		start=distinct[i];
		//cout<<"Start: "<<start<<endl;
		for(j=2;j*start<=2*M;j++){
			temp_max=bin_search(i+1,n-1,j*start);
			// cout<<"temp_max: "<<temp_max<<endl;
			if(temp_max!=-INF){
				max_modulo=max(max_modulo,temp_max%start);
			}
		}
	}
	return max_modulo;
}

int  main(){
	long long int  i,n,res;
	cin>>n;
	for(i=0;i<n;i++){
		cin>>arr[i];
		if(M[arr[i]]==0){
			M[arr[i]]=1;
			distinct.push_back(arr[i]);
		}
	}
	sort(distinct.begin(), distinct.end());
	n=distinct.size();
	res=compute(n);
	cout<<res<<endl;
	return 0;
}