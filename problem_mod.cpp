#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<iostream>
using namespace std;

double array[200];

int main(){
	double mul,max,curr;
	int i,j,k,n;
	cin>>n;
	for(i=0;i<n;i++)
		scanf("%lf",&array[i]);
	sort(array,array+n);
	max=array[n-1];
	for(i=2;i<=n;i++){
		curr=0;
		for(j=n-i;j<n;j++){
			mul=1;
			for(k=n-i;k<n;k++){
				if(k==j){
					mul=mul*array[j];
				}
				else
					mul=mul*(1-array[k]);
			}	
			curr+=mul;
		}
		if(curr>max){
			max=curr;
		}
		else{
			break;
		}
	}	
	printf("%.12lf\n",max);
	return 0;
}



