#include<stdio.h>
#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<ctype.h>
using namespace std;

struct value{
	char ch;
	long long int freq;
};

bool cmp(struct value a,struct value b){
	return a.freq<b.freq;
}	

int main(){

	string a,b;
	long long int c,t,len,i,j;
	struct value res[26];
	c=0;
	scanf("%lld\n",&t);
	while(c++<t){
		res[0].ch='a';
		res[1].ch='b';
		res[2].ch='c';
		res[3].ch='d';
		res[4].ch='e';
		res[5].ch='f';
		res[6].ch='g';
		res[7].ch='h';
		res[8].ch='i';
		res[9].ch='j';
		res[10].ch='k';
		res[11].ch='l';
		res[12].ch='m';
		res[13].ch='n';
		res[14].ch='o';
		res[15].ch='p';
		res[16].ch='q';
		res[17].ch='r';
		res[18].ch='s';
		res[19].ch='t';
		res[20].ch='u';
		res[21].ch='v';
		res[22].ch='w';
		res[23].ch='x';
		res[24].ch='y';
		res[25].ch='z';


		for(i=0;i<26;i++)
			res[i].freq=0;
		getline(cin,a);
		getline(cin,b);
		len=b.length();
		for(i=0;i<len;i++){
			if(b[i]>='a' && b[i]<='z'){
				res[b[i]-'a'].freq++;
			}
			else if(b[i]>='A' && b[i]<='Z'){
				res[b[i]-'A'].freq++;
			}
		}
		
		stable_sort(res,res+26,cmp);

		/*
		for(i=0;i<26;i++){
			printf("%c %lld\n",res[i].ch,res[i].freq);
		}

		*/
		for(i=0;i<len;i++){
			//cout<<b[i]-'a'+'A';
			if(islower(b[i])){
				for(j=0;j<26;j++){
					if(res[j].ch==b[i]){
						//cout<<a[j];
						//printf("%c",a[j]);
						putchar(a[j]);
					}
				}
			}
			else if(isupper(b[i])){
				for(j=0;j<26;j++){
					if(res[j].ch==tolower(b[i])){
						//cout<<a[j]-'a'+'A';
						putchar(toupper(a[j]));
					}
				}
			}
			else{
				putchar(b[i]);
			}
		}

		cout<<endl;
	}
	return 0;
}
