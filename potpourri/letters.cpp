#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;

char  s[2000];
int arr[26];
int main(){
	int i,l,count=0;
	char ch;
	while(scanf("%c",&ch)!=-1){
		if(ch>='a' && ch <= 'z')
			arr[ch-'a']++;
	}


	for(i=0;i<26;i++){
//		cout<<i+1<<'\t'<<arr[i]<<endl;
		if(arr[i]>0)	count++;	
	}
	printf("%d\n",count);
	return 0;
}
