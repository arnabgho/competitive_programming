#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;

#define INF 1000000
//char word[30];
char perm[30][30];
int dist[30];
int mod(int n){return n>0 ? n:-n;}
int main(){
	int i,l,min,max,n;
	char * word;
	word=(char *)calloc(30,sizeof(char));
	while(scanf("%30[^\r]", word)){
	//cout<<word;
	//l=word.length();
		l=0;
		while(word[l]!='\0')l++;
		//cout<<l<<endl;

		for(i=0;i<l;i++)
			perm[11][i]=word[i];

		n=10;
		while(n>0){
			std::prev_permutation(word,word+l);
			for(i=0;i<l;i++){
				perm[n][i]=word[i];
			}
			n--;
		}
		
		for(i=0;i<l;i++)
			word[i]=perm[11][i];
		n=12;
		while(n<=21){
			std::next_permutation(word,word+l);
			for(i=0;i<l;i++){
				perm[n][i]=word[i];
			}
			n++;	
		}


		for(i=1;i<=21;i++){
			min=INF;
			for(int j=1;j<l;j++){
				if(mod(perm[i][j]-perm[i][j-1])<min)
					min=mod(perm[i][j]-perm[i][j-1]);
			}
			dist[i]=min;
		}

		max=-INF;

		for(i=1;i<=21;i++){
			if(dist[i]>max)
				max=dist[i];		
		}
		for(i=1;i<=21;i++){
			if(dist[i]==max){
				cout<<perm[i]<<max<<endl;
				break;
			}
		}

		for(i=1;i<=21;i++)
			cout<<perm[i]<<endl;
		memset(word,'\0',l);
		for(i=1;i<=21;i++)
			memset(perm[i],'\0',l);
		

	}	
	return 0;
}