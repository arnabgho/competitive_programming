#include<stdio.h>
#include<stdlib.h>
#include<iostream>

using namespace std;

int arr[1001];
int num[1001];
int main(){

	int dwarf,candy,n,m,i,j,max,res;
	char ch;
	cin>>n>>m;
	for(i=1;i<=n;i++){
		
		for(j=1;j<=m;j++){
			cin>>ch;	
			if(ch=='G'){
				dwarf=j;
			}
			else if(ch=='S'){
				candy=j;
			}			
		}
		arr[i]=candy-dwarf-1;
	}
	max=0;
	res=0;
	for(i=1;i<=n;i++){
		if(arr[i]<0){
			res=-1;
			break;
		}
		else{
			num[arr[i]]++;
		}
	}
	if(res==-1){
		cout<<"-1\n";		
	}
	else {
		for(i=0;i<=1000;i++){
			if(num[i]>0){
				max++;
				//num[i]=0;
			}
		}
		cout<<max<<endl;
	}	
	return 0;
}
