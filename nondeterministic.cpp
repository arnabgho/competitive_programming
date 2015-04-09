#include <stdio.h>
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

char first[100001][100];
char last[100001][100];

int main(){
	int i,n,k,l,ans,prev,curr;
	char ch;
	string name;
	//name=(char*)malloc(256*sizeof(char));
	cin>>n;
	cin>>ch;
	ungetc(ch,stdin);
	for(i=1;i<=n;i++){
		//cin.getline(name,256);
		//puts(name);
		std::getline (std::cin,name);
		//cout<<name<<endl;
		k=0;
		while(name[k]!=' '){
			first[i][k]=name[k];
			k++;
		}	
		//first[i][k]='\0';
		k++;
		l=0;
		while(name[k]!='\0'){
			last[i][l]=name[k];
			k++;l++;
		}	
		//cout<<first[i]<<endl;
		//cout<<last[i]<<endl;
		//last[i][l]='\0';
	}	
	ans=1;
	cin>>prev;
	//cout<<prev;
	for(i=2;i<=n;i++){
		cin>>curr;
		if(ans){
			/*
			cout<<strcmp(first[prev],first[curr])<<endl;
			cout<<strcmp(first[prev],last[curr])<<endl;
			cout<<strcmp(last[prev],first[curr])<<endl;
			cout<<strcmp(last[prev],last[curr])<<endl;
			*/

			if(!((strcmp(first[prev],first[curr])<0)||(strcmp(first[prev],last[curr])<0)||(strcmp(last[prev],first[curr])<0)||(strcmp(last[prev],last[curr])<0))){
				ans=0;
			}

		}
		prev=curr;
	}
	if(ans)
		cout<<"YES\n";
	else
		cout<<"NO\n";


	return 0;
}