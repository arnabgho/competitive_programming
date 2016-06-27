#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

int res[50001][6];

int arr[50001][6];

int max(int a,int b){return a>b ? a:b;}

int main(){
	int i,j,m,n;
	cin>>m>>n;
	for(i=0;i<m;i++){
		for(j=0;j<n;j++)
			cin>>arr[i][j];	
	}

	res[0][0]=arr[0][0];
	for(i=1;i<m;i++){
		res[i][0]=res[i-1][0]+arr[i][0];
	}

	for(j=1;j<n;j++){
		res[0][j]=res[0][j-1]+arr[0][j];
		for(i=1;i<m;i++)
			res[i][j]=max(res[i][j-1]+arr[i][j],res[i-1][j]+arr[i][j]);
	}
	for(i=0;i<m;i++)
		cout<<res[i][n-1]<<" ";
	cout<<endl;
	return 0;
}