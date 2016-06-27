#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

int mod(int a){return a>0 ? a:-a;}

#define INF 100000000;
//int arr[11111];
int main(){
	int c,t,i,minim,maxim,n,m,k;
	scanf("%d",&t);
	while(t--){
		scanf("%d %d",&n,&m);
		minim=INF;
		maxim=-INF;
		for(i=1;i<=m;i++){
			scanf("%d",&k);
			minim=min(minim,k);
			maxim=max(maxim,k);
		}
		for(i=0;i<n;i++){
			printf("%d ",max(mod(maxim-i),mod(minim-i)));
		}
		printf("\n");
	}
	return 0;
}