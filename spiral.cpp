#include <stdio.h>
#include <iostream>
#include <stdlib.h>


using namespace std;

int arr[50][100];

int main(){
	int m,n,top,down,left,right;
	int i,j,k,l;
	//cin>>m;
	//cin>>n;
	scanf("%d %d",&m,&n);
	cout<<"m: "<<m<<" n: "<<n<<endl;
	//cout<<"Hello";
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			cin>>arr[i][j];
			//cout<<arr[i][j]<<"\t";
		}
		//cout<<endl;
	}
	/*
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			//cin>>arr[i][j];
			cout<<arr[i][j]<<"\t";
		}
		cout<<endl;
	}*/
	//cout<<"Hello";
	left=0;
	right=n-1;
	top=0;
	down=m-1;
	//cout<<"Hello";
	while(top<=down && left<=right){
		//cout<<"Hello";
		i=left;
		while(i<=right){
			cout<<arr[top][i]<<" ";
			i++;
		}
		top++;


		j=top;
		while(j<=down){
			cout<<arr[j][right]<<" ";
			j++;
		}
		right--;

		k=right;
		while(k>=left){
			cout<<arr[down][k]<<" ";
			k--;
		}
		down--;

		l=down;
		while(l>=top){
			cout<<arr[l][left]<<" ";
			l--;
		}
		left++;

		if(top>down || left>right)
			break;
	}

	return 0;
}