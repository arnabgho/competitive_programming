#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;

int main(){
	int prev,curr,n,i,ans,pprev;
	prev=0;
	cin>>n;
	ans=0;
	for(i=1;i<=n;i++){
		cin>>curr;
		if(prev+curr==1 || prev+curr==2)
			ans++;
			
		if(i==n)
			pprev=prev;	
		prev=curr;
	}
	if(!(pprev==1 && prev==0))
		cout<<ans<<endl;
	else
		cout<<ans-1<<endl;
	return 0;
}
