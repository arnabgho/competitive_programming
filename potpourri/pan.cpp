#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<iostream>
#include<string.h>
using namespace std;

char left_arr[100];
char right_arr[100];
char standby_arr[100];
int mod(int a){
	return a>0 ? a:-a;
}

int main(){

	int i,left,right,standby;
	string s;
	char ch;
	left=0;
	right=0;
	standby=0;
	cin>>ch;
	cout<<ch;
	
	
	while(ch!='|'){
		left++;	
		left_arr[left]=ch;
		cout<<ch;
		cin>>ch;
	}
	cout<<ch;
	cin>>ch;
	while(ch!='\n'){
		right++;
		right_arr[right]=ch;
		cout<<ch;		
		cin>>ch;
	}	

	cin>>standby_arr+1;
	standby=strlen(standby_arr);
	cout<<"Rubbish"<<endl;
	if(mod(left-right)>standby){
		cout<<"Impossible";
	}
	else{
		if(right>left){
			if((right-left+standby)%2!=0)
				cout<<"Impossible";
			else{
				for(i=1;i<=left;i++)
					cout<<left_arr[i];
				for(i=1;i<=(right-left+standby)/2;i++)
					cout<<standby_arr[i];
				cout<<"|";
				for(i=1;i<=right;i++)
					cout<<right_arr[i];
				for(i=(right-left+standby)/2+1;i<=standby;i++)
					cout<<standby_arr[i];			
			
			}	
		}
		else if(right<left){
				for(i=1;i<=left;i++)
					cout<<left_arr[i];
				for(i=1;i<=(right-left+standby)/2;i++)
					cout<<standby_arr[i];
				cout<<"|";
				for(i=1;i<=right;i++)
					cout<<right_arr[i];
				for(i=(right-left+standby)/2+1;i<=standby;i++)
					cout<<standby_arr[i];		
		}
		else if(right==left){
			if(standby%2!=0){
				cout<<"Impossible";
			}
			else{
				for(i=1;i<=left;i++)
					cout<<left_arr[i];
				for(i=1;i<=standby/2;i++)
					cout<<standby_arr[i];
				cout<<"|";	
				for(i=1;i<=right;i++)
					cout<<right_arr[i];
				for(i=standby/2+1;i<=standby;i++)
					cout<<left_arr[i];
					
			}
		}
		
	}






}
