#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <string>
using namespace std;

int DP[100000][500];

void initialize(int s,int m){
	for(int i=0;i<s;i++){
		for(int j=0;j<m;j++)
			DP[i][j]=0;
	}
}

int compute(string &s,int m,int l,int len){
	int i,j,count=0,dig,temp,temp2;
	dig=s[0]-'0';
	DP[0][dig%m]=1;
	//if (dig%m==l) count++;
	for(i=1;i<len;i++){
		dig=s[i]-'0';
		DP[i][dig%m]=1;
		//cout<<"i "<<i<<" dig "<<dig%m<<endl;
		for(j=0;j<m;j++){
			if(DP[i-1][j]){
				//cout<<"i "<<i<<" dig "<<(j*10+dig)%m<<endl;
				temp=(j*10+dig)%m;
				//cout<<"DP before add "<<DP[i][temp]<<endl;
				temp2=DP[i-1][j]+DP[i][temp];
				//cout<<"temp2 "<<temp2<<endl;	
				//cout<<"DP earlier"<<DP[i-1][j]<<endl;

				DP[i][temp]=temp2;	
				//cout<<"DP "<<DP[i][temp]<<endl;

			}
		}
	}
	for(i=0;i<len;i++){
		if(DP[i][l]) count+=DP[i][l];
	}


	//for(i=0;i<len;i++){
		//for(j=0;j<m;j++) cout<<DP[i][j]<<"  ";
		//cout<<endl;	
	//}
	return count;
}

int main(){
	int len,q,m,l,res;
	int i,j,count=0,dig,temp,temp2;
	string s="";
	cin>>s;
	cin>>q;
	len=s.size();
	while(q--){
		cin>>m>>l;
		res=compute(s,m,l,len);
		cout<<res<<endl;		
		initialize(len,m);
	}
	return 0;
}