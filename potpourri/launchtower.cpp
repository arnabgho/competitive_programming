#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;

int DP[100001];

char s[100001];
int main(){
	int Q,M,L,size,count,i,j;
	//string s;
	//cin>>s;
	//cout<<s;
	scanf("%s",s);
	size=strlen(s);
	//cin>>Q;
	scanf("%d",&Q);
	while(Q--){
		//cin>>M>>L;
		scanf("%d %d",&M,&L);
		count=0;
		for(i=0;i<size;i++){
			DP[i]=(s[i]-'0'-L)%M;
			if(DP[i]==0)
				count++;
			for(j=i+1;j<size;j++){
				DP[j]=(DP[j-1]*10+s[j]-'0'+9*L)%M;
				if(DP[j]==0)
					count++;
			}
		}
		//cout<<count<<endl;
		printf("%d\n",count );
	}

	return 0;
}