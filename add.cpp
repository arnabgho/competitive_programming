#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<iostream>
using namespace std;
int max_random(int n){
	int a,b,c;
	a=n%10;
	n/=10;
	b=n%10;
	n/=10;
	c=n%10;
	if(a>=0 && b>=0 && c>0){
		if(c>=a && c>=b){
			if(b>=c) return 100*c+10*b+a;
			else return 100*c + 10*a +b;
		}
		else if(a>=b && a>=c){
			if(b>=c) return 100*a+10*b+c;
			else return 100*a + 10*c +b;
		}
		else if(b>=a && b>=c){
			if(a>=c) return 100*b+10*a+c;
			else return 100*b + 10*c +a;
		}
		
	}
	else if(a>=0 && b>0 && c==0){
		if(a>=b){
			return 10*a+b;
		}
		else {
			return 10*b+1*a;
		}
	}
	else if(a>=0 && b==0 && c==0){
		return a;
	}
}
int max(int a,int b){return a>b ? a:b;}

int dp[10];
int arr[10];
int main(){
	int n,i,maxim,sum,j;
	cin>>n;
	for(i=1;i<=n;i++){
		cin>>arr[i];
	}
	//cout<<"[5] :"<<arr[5]<<endl;
	for(i=1;i<=n;i++){
		sum=0;
		maxim=0;
		for(j=i;j>=1;j--){
			sum+=arr[j];
			maxim=max(maxim,max_random(dp[j-1]+sum));
			//cout<<" i "<<i<<" j: "<<j<<" maxim : "<<maxim<<endl;
		}	
		dp[i]=maxim;
		//cout<<"dp[i] :"<<dp[i]<<endl;
	}
	cout<<dp[n]<<endl;
}