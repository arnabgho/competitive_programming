#include <stdio.h>
#include <algorithm>

using namespace std;

long long int arr[100];

bool cmp(long long int a,long long int b){
	return a>b;
}

int main(){
	long long int c,t,n,m,i,ans,cum;
	scanf("%lld",&t);
	while(t--){
		scanf("%lld %lld",&n,&m);
		for(i=0;i<n;i++)
			scanf("%lld",&arr[i]);
		sort(arr,arr+n,cmp);
		ans=0;cum=0;i=0;
		while(cum<m && i<n){
			cum+=arr[i++];
			ans++;
		}
		
		if(cum>=m and ans<=n)
			printf("%lld\n", ans);
		else
			printf("-1\n");
	}
	return 0;
}