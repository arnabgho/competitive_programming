#include<stdio.h>
#include<iostream>
#include<stdlib.h>

using namespace std;

int arr[1001];

int main(){
	int n,i,s,d,left,right;
	cin>>n;
	for(i=1;i<=n;i++)
		cin>>arr[i];
	s=0;d=0;left=1;right=n;
	for(i=1;i<=n;i++){
		if(i%2==1){
			if(arr[left]>arr[right]){
				
				s+=arr[left];
				left++;
			}
			else{
				
				s+=arr[right];
				right--;
			}
		}
		else{
			if(arr[left]>arr[right]){
				
				d+=arr[left];
				left++;
			}
			else{
				
				d+=arr[right];
				right--;
			}			
		
		}
		
	}
	printf("%d %d\n",s,d);	



	return 0;
}
