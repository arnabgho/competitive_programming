 #include <stdio.h>
#include <iostream>

using namespace std;

long long int arr[100001];

long long int cum[100001];

long long int min(long long int a,long long int b){return a<b ? a:b;}

long long int max(long long int a,long long int b){return a>b ? a:b;}


long long int find_heap(long long int k,long long int left,long long int right){

	if(right<left)
		return -1;
	int mid=(left+right)/2;

	if(k>cum[mid])
		return find_heap(k,mid+1,right);
	else if(k==cum[mid])
		return mid;
	else if(k<cum[mid]){
		if(find_heap(k,left,mid-1)!=-1)
			return min(mid,find_heap(k,left,mid-1));
		else
			return mid;
	}
}

int main()
{
	long long int n,sum,i,m,k;
	cin>>n;
	sum=0;
	for(i=1;i<=n;i++){
		cin>>arr[i];
		sum+=arr[i];
		cum[i]=sum;
	}
	cin>>m;
	for(i=1;i<=m;i++){
		cin>>k;
		cout<<find_heap(k,0,n)<<endl;
	}
	return 0;
}