#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int DP[500][50];
int Villages[500];
int i,j,v,p,a,minim;

int median[500][500];

void precompute(){
	int med,sum;
	for(i=1;i<=v;i++){
		for(j=i;j<=v;j++){
			med=(i+j+1)/2;
			sum=0;
			for(int k=i;k<=j;k++){
				sum+=abs(Villages[k]-Villages[med]);
			}
			median[i][j]=sum;
			// cout<<median[i][j]<<" ";
		}
		// cout<<endl;
	}
}

int compute(){
	for(i=1;i<=v;i++){
		for(j=1;j<=p;j++){
			if(j>=i){
				DP[i][j]=0;
				continue;
			}
			DP[i][j]=median[1][i];
			for(int k=1;k<i;k++){
				// cout<<DP[k][j-1]+median[k+1][i]<<endl;
				if(DP[k][j-1]+median[k+1][j]>0)
					DP[i][j]=min(DP[i][j],DP[k][j-1]+median[k+1][i]);
			}
		}
	}
	return DP[v][p];
}


int main() {
	cin>>v;
	cin>>p;
	for(i=1;i<=v;i++){
		cin>>a;
		Villages[i]=a;
	}
	// sort(Villages.begin(),Villages.begin()+v);
	for(i=1;i<=v;i++)
		// cout<<Villages[i]<<endl;
	precompute();

	for(i=1;i<=v;i++){
		for(j=1;j<=p;j++){
			DP[i][j]=63;
		}
	}
	int ans=compute();

	cout<<ans<<endl;
	return 0;
}