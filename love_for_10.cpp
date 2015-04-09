#include <stdio.h>
#include <algorithm>
#include <string>
#include <iostream>
#include <stdlib.h>

using namespace std;

int DP[1100][1100];
int digits[1100];

#define INF 1000000000;

int main(){
	string s="";
	cin>>s;
	int i,n,j,len,maxlen,temp_max;
	n=s.size();
	for(i=0;i<n;i++)
		digits[i]=s[i]-'0';
	maxlen=0;
	for(i=0;i<n;i++){
		if(digits[i]==5){
			DP[i][i]=1;
			maxlen=1;
		}
	}
	for(i=0;i+1<n;i++){
		if(digits[i]+digits[i+1]==10){
			DP[i][i+1]=2;
			maxlen=2;
		}
		else{
			DP[i][i+1]=max(DP[i][i],DP[i+1][i+1]);
		}
	}

	for(len=3;len<=n;len++){
		for(i=0;i<n-len+1;i++){
			j=i+len-1;
			if(digits[i]+digits[j]==10){
				temp_max=max(DP[i+1][j-1]+2,DP[i+1][j]);
				DP[i][j]=max(temp_max,DP[i][j-1]);
			}
			else{
				temp_max=max(DP[i+1][j-1],DP[i+1][j]);
				DP[i][j]=max(temp_max,DP[i][j-1]);				
			}
			maxlen=max(maxlen,DP[i][j]);
		}
	}

	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			cout<<DP[i][j]<<" ";
		}
		cout<<endl;
	}

	cout<<maxlen<<endl;
	return 0;
}