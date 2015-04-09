#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<iostream>

using namespace std;
		int arr[200000];
	 int countBlack(string ballSequence,int repetitions){
		int i,j,len,tot,nb,top,bot,dir;
		len=ballSequence.length();
		tot=len*repetitions;
		for(i=1;i<=tot;i++){
			if(ballSequence[(i-1)%len]=='B')
				arr[i]=1;
			else
				arr[i]=0;	
		}
		for(i=1;i<=tot;i++)
			cout<<arr[i]<<endl;
		top=1;
		bot=tot;
		nb=0;
		dir=1;
		cout<<"-------------------------"<<endl;
		while(tot>0){
			cout<<top<<"  "<<bot<<" "<<nb<<endl;
			if(dir==1){
				if((arr[top]+nb)%2==1){
					nb++;
					top++;
					tot--;
					continue;
				}
				else{
					top++;
					tot--;
					dir=0;
					continue;
				}
			}
			else if(dir==0){
				if((arr[bot]+nb)%2==1){
					nb++;
					bot--;
					tot--;
					continue;
				}
				else{
					bot--;
					tot--;
					dir=1;
					continue;
				}
			}
		}
		return nb;	
	}
	
int	main(){
	string ballSequence;
	int repetitions;
	cin>>ballSequence;
	cin>>repetitions;
	cout<<countBlack(ballSequence,repetitions)<<endl;
}
