#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<iostream>
using namespace std;

int arr[13];
int res[7];
int main(){
	int i,c,t,check,count;
	char ch;
	c=0;
	string re[7]={"","1x12","2x6","3x4","4x3","6x2","12x1"};
	//scanf("%d",&t);
	cin>>t;
	while(c++<t){
		count=0;
		for(i=1;i<=6;i++)
			res[i]=0;
		for(i=1;i<=12;i++){
			cin>>ch;
			if(ch=='X')
				arr[i]=1;
			else 
				arr[i]=0;		
		}	
		check=0;
		for(i=1;i<=12;i++){
			check=(arr[i]);
			if(check==1)
				break;
		}
		if(check==1){
			count++;
			res[1]=1;
		}
		
		check=0;
		for(i=1;i<=6;i++){
			check=(arr[i]&arr[i+6]);
			if(check==1)
				break;
		}
		if(check==1){
			count++;
			res[2]=1;
		}
		check=0;
		for(i=1;i<=4;i++){
			check=(arr[i]&arr[i+4]&arr[i+8]);
			if(check==1)
				break;
		}
		if(check==1){
			count++;
			res[3]=1;
		}
		check=0;
		for(i=1;i<=3;i++){
			check=(arr[i]&arr[i+3]&arr[i+6]&arr[i+9]);
			if(check==1)
				break;
		}
		if(check==1){
			count++;
			res[4]=1;
		}
		check=0;
		for(i=1;i<=2;i++){
			check=(arr[i]&arr[i+2]&arr[i+4]&arr[i+6]&arr[i+8]&arr[i+10]);
			if(check==1)
				break;
		}
		if(check==1){
			count++;
			res[5]=1;
		}
		check=0;
		for(i=1;i<=1;i++){
			check=(arr[i]&arr[i+1]&arr[i+2]&arr[i+3]&arr[i+4]&arr[i+5]&arr[i+6]&arr[i+7]&arr[i+8]&arr[i+9]&arr[i+10]&arr[i+11]);
			if(check==1)
				break;
		}
		if(check==1){
			count++;
			res[6]=1;
		}
		cout<<count<<" ";
		for(i=1;i<=6;i++){
			if(res[i])
				cout<<re[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
