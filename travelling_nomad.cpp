#include <stdio.h>
#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;

struct ob{
	int t,no_of_ways,town;
	ob(): no_of_ways(0),town(-1){};
};
//struct ob DP[10001];
int arr[10001];

int compute(int n,int dest,int m ,struct ob *DP){
	int town=0,i,j,ans=0;
	//DP[arr[0]].no_of_ways=1;
	int source=arr[0];
	//DP[source].no_of_ways=1;
	DP[source].town=0;
	DP[dest].town=n+1;
	for(i=source+1;i<dest;i++){
		if(DP[i].town==n)
			ans+=DP[i].no_of_ways;
		town=DP[i].town;
		if(town==-1)
			continue;
		for(j=1;j<=m;j++){
			//cout<<"i:  "<<i<<"  Town : " <<town<<"\t";
			//cout<<"Next Town: "<<DP[i+j].town<<endl;
			if(DP[i+j].town==town+1){
				DP[i+j].no_of_ways+=DP[i].no_of_ways;
			}
		}
	}
	
	for(i=0;i<=dest;i++){
		cout<<"i: "<<i<<endl;
		cout<<"Town: "<<DP[i].town<<endl;
		cout<<"no_of_ways: "<<DP[i].no_of_ways<<endl;
	}
	//return DP[dest].no_of_ways;
		return ans;
}

int main(){
	int t,a,m,i,n,l,r,j,count,dest;
	cin>>t;
	struct ob *DP ;
	DP=(struct ob *)malloc(40001*sizeof(struct ob));
	while(t--){
		cin>>a>>m;
		//cout<<a;
		//cout<<m;
		for(i=0;i<a;i++){
			cin>>arr[i];
			//cout<<arr[i];
		}
		cin>>n;
		for(i=1;i<=n;i++){
			cin>>l>>r;
			//count=1;
			for(j=arr[l];j<=arr[r];j++){
				if(i==1){
					DP[j].no_of_ways=1;
				}
				DP[j].town=i;
			}
		}
		dest=arr[a-1];
		//cout<<"dest "<<dest<<endl;
		cout<<compute(n,dest,m,DP)<<endl;
	}
	return 0;
}