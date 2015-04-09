#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<iostream>

using namespace std;
int a[400];
int main(){

	long long int n,i,sum=0;
	
	cin>>n;
	for(i=1;i<=n;i++){
		cin>>a[i];
		sum+=a[i];
	}
	while(sum>0){
		for(i=1;i<=n-1;i++){
			if(a[i]>0){

				a[i]--;
				sum--;
				if(sum==0){
					cout<<"P";
					break;
				}	
				else{
					cout<<"PR";					
				}
						
			}
			else{
				cout<<'R';
			}		
		}
		
		
		if(sum==0)
			break;
			
		for(i=n;i>=2;i--){
			if(a[i]>0){
				
				a[i]--;
				sum--;
				if(sum==0){
					cout<<"P";
					break;
				}
				else{
					cout<<"PL";
				}	
			}
			else{
				cout<<'L';
			}		
		
		}
	}
	cout<<endl;
	return 0;
}
