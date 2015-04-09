#include<stdio.h>
#include<iostream>
 
 using namespace std;

long long int players[5000];
 int main(){
 	long long int i,n,m,k,fedor,num,check,ans;
 	cin>>n>>m>>k;

 	for(i=0;i<=m;i++)
 		cin>>players[i];
 	fedor=players[m];

 	ans=0;
 	for(i=0;i<m;i++){
 		num=0;
 		check=fedor^players[i];
 		while(check>0){
 			if(check%2==1){
 				num++;
 			}
 			check=check>>1;
 		}
 		if(num<=k)
 			ans++;
 	}
 	cout<<ans<<endl;
 	return 0;
 }