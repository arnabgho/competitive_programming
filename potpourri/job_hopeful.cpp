#include<stdio.h>
#include<iostream>

using namespace std;

long long int arr[10000];
long long int cum[10000];
long long int res[5001][5001];
long long int max(long long int a,long long int b){return a>b ? a:b;}

long long int number(long long int *cum,long long int n,long long int m,long long int k,long long int start){
	long long int maxim,i;
	maxim=0;
	if(start>n+1-k*m)
		return 0;
	else if(k==1){
		if(n-start+1<m)
			return 0;
		else{
				for(i=start;i<=n-m+1;i++){
					if(res[k-1][m+i]==0){
						res[k-1][m+i]=number(cum,n,m,k-1,m+i);
					}
					maxim=max(maxim,cum[i]+res[k-1][m+i]);
					//cout<<"cum "<<cum[i]<<endl;
					//cout<<number(cum,n,m,k-1,m+i)<<endl;
				}
				return maxim;
			}
		}
	else if(k==0){
		return 0;
	}
	
	for(i=start;i<=n-m+1-m*(k-1);i++){
		if(res[k-1][m+i]==0){
			res[k-1][m+i]=number(cum,n,m,k-1,m+i);
		}
		maxim=max(maxim,cum[i]+res[k-1][m+i]);
		//cout<<"cum "<<cum[i]<<endl;
		//cout<<number(cum,n,m,k-1,m+i)<<endl;
	}
	return maxim;
} 


int main(){
	long long int n,m,k,i,maxim,sum,prev;
	cin>>n>>m>>k;
	sum=0;
	for(i=1;i<=n;i++){
		cin>>arr[i];
		sum+=arr[i];
	}

	for(i=1;i<=m;i++)
		cum[1]+=arr[i];
	//cout<<"CUM "<<cum[1]<<endl;
	for(i=2;i<=n-m+1;i++){
		cum[i]=cum[i-1]-arr[i-1]+arr[i+m-1];
	//	cout<<"CUM "<<cum[i]<<endl;
	}	

	maxim=0;
	//cout<<sum<<endl;
	prev=1;
	for(i=2;i<=n;i++){
		if(arr[i]!=arr[i-1]){
			prev=0;
			break;
		}
	}
	if(sum>0 & !prev){
		for(i=1;i<=n-m+1-m*(k-1);i++){
			if(res[k-1][m+i]==0){
				res[k-1][m+i]=number(cum,n,m,k-1,m+i);
			}
			maxim=max(maxim,cum[i]+res[k-1][m+i]);	
		}
		cout<<maxim<<endl;
	}
	else{
		if(sum==0)
			cout<<"0\n";
		else if(prev)
			cout<<k*m*arr[1]<<endl;
	}
	return 0;
	
}