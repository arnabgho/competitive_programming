#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<iostream>
using namespace std;

long long int arr[100001];

int main(){

	long long int i,n,res,diff,flag,chance,val;
	cin>>n;
	for(i=1;i<=n;i++)
		cin>>arr[i];
	sort(arr+1,arr+n+1);
	if(n>=3){
		flag=1;
		chance=0;
		for(i=1;i<=n-2;i++){
			if(2*arr[i+1]!=arr[i]+arr[i+2]){
			
				if((arr[i+1]-arr[i])*2==(arr[i+2]-arr[i+1])){
					if(chance==0){
						chance++;
						val=2*arr[i+1]-arr[i];
						i+=2;
						//cout<<val;	
					}	
					else{
					 flag=0;
					 break;
					 }		
				}
				else{
					flag=0;
					break;
				}	
			}		
		}	
		if(flag==0){
			cout<<"0"<<endl;
		}
		else if(chance==1){
			cout<<"1\n"<<val;
		}
		else {
			cout<<"2\n";
			cout<<arr[1]-(arr[2]-arr[1])<<" "<<arr[n]+(arr[2]-arr[1]);
		}	
	}
	else if(n==2){
		if((arr[1]+arr[2])%2==0){
			cout<<"3\n";
			cout<<arr[1]-(arr[2]-arr[1])<<" "<<(arr[2]+arr[1])/2<<" "<< arr[2]+(arr[2]-arr[1]);
		}
		else{
			cout<<"2";
			cout<<arr[1]-(arr[2]-arr[1])<<" "<< arr[2]+(arr[2]-arr[1]);			
		}
	}


	else if(n==1){
		cout<<"-1";
	}
	return 0;
}
