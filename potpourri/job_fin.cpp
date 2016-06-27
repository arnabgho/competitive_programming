#include<stdio.h>
#include<iostream>
#include<map>

using namespace std;

long long int arr[10000];
long long int cum[10000];

struct map_help{
	long long int k,m;
	/*
	 bool const operator==(const map_help &o) {
        return this->k == o.k && this->m == o.m;
    }
    bool const operator<(const map_help &o) {
        return this->k < o.k || (this->k == o.k && this->m < o.m);
    }
     bool const operator>(const map_help &o) {
        return this->k > o.k || (this->k == o.k && this->m > o.m);
    }*/
};
inline bool operator<(map_help const& left, map_help const& right) {
  if (left.k < right.k) { return true; }
  if (left.k > right.k) { return false; }
}
inline bool operator==(map_help const& left, map_help const& right) {
  if ((left.k == right.k) && (left.m==right.m)) { return true; }
  else return false;
}
std::map<struct map_help,long long int > dp;
long long int max(long long int a,long long int b){return a>b ? a:b;}

long long int number(long long int *cum,long long int n,long long int m,long long int k,long long int start){
	long long int maxim,i;
	map_help temp;
	
	
	maxim=0;
	if(start>n+1-k*m)
		return 0;
	else if(k==1){
		if(n-start+1<m)
			return 0;
		else{
				for(i=start;i<=n-m+1;i++){
					
						maxim=max(maxim,cum[i]);
					}
					//cout<<"cum "<<cum[i]<<endl;
					//cout<<number(cum,n,m,k-1,m+i)<<endl;
				
				temp.k=k;
				temp.m=start;
				dp[temp]=maxim;
				return maxim;
			}
		}
	else if(k==0){
		return 0;
	}
	else{
	for(i=start;i<=n-m+1-m*(k-1);i++){
		temp.k=k-1;
		temp.m=m+i;
		if(dp[temp]==0)
			maxim=max(maxim,cum[i]+number(cum,n,m,k-1,m+i));
		else
			maxim=max(maxim,dp[temp]);
		//cout<<"cum "<<cum[i]<<endl;
		//cout<<number(cum,n,m,k-1,m+i)<<endl;

	}
	temp.k=k;
	temp.m=start;
	dp[temp]=maxim;
	return maxim;
	}
} 


int main(){
	long long int n,m,k,i,maxim;
	cin>>n>>m>>k;
	for(i=1;i<=n;i++)
		cin>>arr[i];

	for(i=1;i<=m;i++)
		cum[1]+=arr[i];
	//cout<<"CUM "<<cum[1]<<endl;
	for(i=2;i<=n-m+1;i++){
		cum[i]=cum[i-1]-arr[i-1]+arr[i+m-1];
	//	cout<<"CUM "<<cum[i]<<endl;
	}	

	maxim=0;
	for(i=1;i<=n-m+1-m*(k-1);i++){
		maxim=max(maxim,cum[i]+number(cum,n,m,k-1,m+i));
	}
	cout<<maxim<<endl;
	
	return 0;
	
}