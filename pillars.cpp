#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

long long int mod(long long int x){return x>0 ? x:-x;}

long long int Prev[100001];
long long int DP[100001];
long long int Height[100001];

#define INF 10000000000000000;

long long int max(long long int a,long long int b){return a>b ? a:b;}

void compute(long long int n,long long int d){
	long long int i,j,maxim;
	//cout<<"Hi\n";
	//Prev[1]=1;
	for(i=1;i<=n;i++){
		maxim=1;
		for(j=1;j<i;j++){
			//cout<<"i: "<<i<<" j :"<<j<<endl;
			if(mod(Height[i]-Height[j])>=d){
				//cout<<"Hi 1"<<endl;
				if(DP[j]+1>maxim){
					//cout<<"Hi 2"<<endl;
					maxim=DP[j]+1;
					Prev[i]=j;
				}
			}
		}
		DP[i]=maxim;
	}
}

void path(long long int i){
	if (Prev[i]==-1)
		cout<<i<<" ";
	else{
		path(Prev[i]);
		cout<<i<<" ";
	}
}

int main()
{
	long long int i,n,d,maxim,pos;
	cin>>n>>d;
	for(i=1;i<=n;i++)
		cin>>Height[i];

	//memset(DP,1,n+1);

	for(i=1;i<=n;i++){
		//cout<<DP[i]<<endl;
		DP[i]=1;
		Prev[i]=-1;
	}
	//memset(Prev,-1,n+1);

	compute(n,d);

	maxim=-INF;

	for(i=1;i<=n;i++){

		//cout<<DP[i]<<endl;
		if(DP[i]>maxim){
			maxim=DP[i];
			pos=i;
		}
	}

	cout<<maxim<<endl;
	path(pos);
	cout<<endl;
	return 0;
}