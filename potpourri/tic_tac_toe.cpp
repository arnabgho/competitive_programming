#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string.h>
#include <string>
#include <unordered_map>
using namespace std;

std::unordered_map<std::string,int > mymap;
//2 for . 
//0 for O
//1 for X

int alreadyWon(string state,int num1,int num0){
	if (num1<3 && num0 <3)
		return 0;
	else{
		if((state[0]==state[1])&&(state[1]==state[2])&&(state[0]!='.'))
			return 1;
		else if((state[3]==state[4])&&(state[4]==state[5])&&(state[3]!='.'))
			return 1;
		else if((state[6]==state[7])&&(state[7]==state[8])&&(state[6]!='.'))
			return 1;
		else if((state[0]==state[4])&&(state[4]==state[8])&&(state[0]!='.'))
			return 1;
		else if((state[6]==state[4])&&(state[4]==state[2])&&(state[6]!='.'))
			return 1;
		else if((state[0]==state[3])&&(state[3]==state[6])&&(state[0]!='.'))
			return 1;
		else if((state[1]==state[4])&&(state[4]==state[7])&&(state[1]!='.'))
			return 1;
		else if((state[2]==state[5])&&(state[5]==state[8])&&(state[2]!='.'))
			return 1;		
		else 
			return 0;
	}
	return 0;
}

int isValid(string state,int num1,int num0){
	int val,ret;

	string temp;
	if((num0==num1)&&(num0==0))
		return 1;
	else if((num0==num1)&&(num0==1))
		return 1;
	else if((num0==0)&&(num1==1))
		return 1;
	else if((num0>num1))
		return 0;
	else if(num1-num0>1)
		return 0;
	else if(alreadyWon(state,num1,num0))
		return 0;
	else{
		temp=state;
		if(num1==num0+1){
			cout<<"Hi\n";
			val=0;
			for(int i=0;i<9;i++){
				if(state[i]=='X'){
					state[i]='.';			//change state
					std::unordered_map<std::string,int>::const_iterator it=mymap.find(state);
					if(it==mymap.end()){
						ret=isValid(state,num1-1,num0);
						//mymap.insert(std::make_pair<std::string,int>(state,ret));
						std::pair<std::string,int> t (state,ret);
						mymap.insert(t);
					}
					else{
						ret=it->second;
					}
					cout<<"ret in f : "<<ret<<endl;
					val=val|ret;	
					state[i]='X';			//Restore state
				}
			}
			return val;
		}
		else if(num0==num1){
			cout<<"Hi2\n";
			val=0;
			for(int i=0;i<9;i++){
				if(state[i]=='O'){
					state[i]='.';			//change state
					std::unordered_map<std::string,int>::const_iterator it=mymap.find(state);
					if(it==mymap.end()){
						ret=isValid(state,num1,num0-1);
						//mymap.insert(std::make_pair<std::string,int>(state,ret));
						std::pair<std::string,int> t (state,ret);
						mymap.insert(t);
					}
					else{
						ret=it->second;
					}
					cout<<"ret in f2 : "<<ret<<endl;
					val=val|ret;	
					state[i]='O';			//Restore state
				}
			}			
			return val;
		}
		else{
			return 0;
		}

	}
}

int main()
{
	int c,t,num0,num1,i,j,k,ans,ret,val,res;
	char ch;
	string state;
	cin>>t;
	state="000000000";
	//cout<<state;
	while(t--){
		k=0;
		num0=0;
		num1=0;
		for(i=0;i<3;i++){
			for(j=0;j<3;j++){
				cin>>ch;
				state[k++]=ch;
				if(ch=='X')
					num1++;
				else if(ch=='O')
					num0++;
			}
		}

		//cout<<state;

		res=alreadyWon(state,num1,num0);

		//cout<<"num1 :"<<num1<<" num0: "<<num0<<endl;

		cout<<"res:"<<res<<endl;

		if(res){
			if(num1==num0+1){
				val=1;
				for(int i=0;i<9;i++){
					if(state[i]=='X'){
						state[i]='.';			//change state
							ret=alreadyWon(state,num1-1,num0);
						val=val&ret;	
						//cout<<"state: "<<state<<endl;
						//cout<<"ret :"<<ret<<endl;
						state[i]='X';			//Restore state
					}
				}
				if(val==1)
					ans=0;
				else 
					ans=1;
			}
			else if(num0==num1){
				val=1;
				for(int i=0;i<9;i++){
					if(state[i]=='O'){
						state[i]='.';			//change state
							ret=alreadyWon(state,num1-1,num0);
						val=val&ret;	
						state[i]='O';			//Restore state
					}
				}
				if(val==1)
					ans=0;
				else 
					ans=1;		
			}
			else
				ans=0;
		}

		else{
			ans=isValid(state,num1,num0);		
		}
		if(ans)
			cout<<"yes\n";
		else
			cout<<"no\n";
		if(t!=0)
			scanf("\n");
	}

	/* code */
	return 0;
}