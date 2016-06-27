#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<iostream>

using namespace std;



int main(){

	int i,l,start,end,*re1,*re2;
	string mystr,res1,res2;	
	char c;
	//scanf("%s",s);
	//printf("%s\n",s);
	
	getline(cin,mystr);
	//cout<<mystr<<'\n';
	//cout<<mystr.length()<<'\n';
	re1=(int *)calloc(mystr.length()+2,sizeof(int));
	re2=(int *)calloc(mystr.length()+2,sizeof(int));	

	re1[0]=0;
	re2[0]=1;

	re1[1]=mystr[0]-'0';
	re2[1]=mystr[0]-'0'-1;
	for(i=1;i<mystr.length()-1;i++){
		re1[i+1]=mystr[i]-'0'-re1[i]-re1[i-1];
		if(re1[i+1]<0||re1[i+1]>1){
			res1="NONE";
			break;	
		}		
	}
	
	i=mystr.length()-1;
	if(mystr[i]-'0'!=re1[i]+re1[i-1])
		res1="NONE";
	
	for(i=1;i<mystr.length()-1;i++){
		re2[i+1]=mystr[i]-'0'-re2[i]-re2[i-1];
		if(re2[i+1]<0||re2[i+1]>1){
			res2="NONE";
			break;	
		}		
	}
	
	i=mystr.length()-1;
	if(mystr[i]-'0'!=re2[i-1]+re2[i])
		res2="NONE";
	
	if(res1!="NONE"){
		for(i=0;i<mystr.length();i++){
			//res1=res1+'0'+re1[i];
			c='0'+re1[i];
			cout<<c<<"\n";
			res1+=c;
		}
	}
	

	if(res2!="NONE"){
		for(i=0;i<mystr.length();i++){
			//res2=res2+'0'+re2[i];
			c='0'+re2[i];
			cout<<c<<"\n";
			res2+=c;
		}
	}

	cout<<"{\""<<res1<<"\"},{\""<<res2<<"\"}\n";
	
	return 0;
}
