#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
using namespace std;

char first[100001][100];
char last[100001][100];
int perm[100001];
int main(){	
	int i,n,k,l,ans;
	char ch;
	string name;
	char * prev,*min,*max;
	prev=(char*)malloc(256*sizeof(char));
	min=(char*)malloc(256*sizeof(char));
	max=(char*)malloc(256*sizeof(char));
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

	for(i=1;i<=n;i++)
		cin>>perm[i];

	//cout<<first[perm[1]]<<endl;

	if(strcmp(first[perm[1]],last[perm[1]])<0)
		strcpy(prev,first[perm[1]]);
	else
		strcpy(prev,last[perm[1]]);
	ans=1;
	//cout<<prev<<endl;
	for(i=2;i<=n;i++){

		if(strcmp(first[perm[i]],last[perm[i]])<0){
			strcpy(min,first[perm[i]]);
			strcpy(max,last[perm[i]]);
		}

		else{
			strcpy(min,last[perm[i]]);
			strcpy(max,first[perm[i]]);
		}

		if(strcmp(prev,min)<0){
			strcpy(prev,min);
			//cout<<prev<<endl;
			continue;
		}
		else if(strcmp(prev,max)<0){
			strcpy(prev,max);
			//cout<<prev<<endl;
			continue;
		}
		else{
			ans=0;
			//cout<<"In No "<<prev<<endl;
			break;
		}
	}
	if(ans)
		cout<<"YES\n";
	else
		cout<<"NO\n";
	return 0;
}