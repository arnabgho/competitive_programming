#include<stdio.h>
#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
long long int arr[20001];

int main(){
	std:: queue<int> times;
	
	long long int c,t,n,i,val,h,m,s,T,max;
	cin>>t;
	for(c=1;c<=t;c++){
		cin>>n;
		val=0;
		max=0;
		while(!times.empty()){
			times.pop();
		}
		for(i=1;i<=n;i++){
			scanf("%lld:%lld:%lld",&h,&m,&s);
			s+=3600*h + 60*m;
			arr[i-1]=s;
		}
		sort(arr,arr+n);
		for(i=0;i<n;i++){
			times.push(arr[i]);
		}
		cin>>T;
		//cout<<"back"<<times.back()<<"front"<<times.front()<<endl;
		if(times.size()!=0){
		while(1){
			//cout<<"Inside back"<<times.back()-times.front()<<"front"<<times.front()<<endl;
			if (times.back()-times.front()>T){
				times.pop();
			}
			else{
				break;
			}
		}
		}
		val=times.size();
		cout<<"Case "<<c<<": "<<val<<endl;
	}
	return 0;	
}
