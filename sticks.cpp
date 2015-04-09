#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;
int arr[10];

int main(){
	int i,k,min,mid,max,count;
	for(i=1;i<=6;i++){
		cin>>k;
		arr[k]++;
	}
	count=0;
	min=0;max=0;mid=0;
	for(i=1;i<=9;i++){
		if(arr[i]>0)
			count++;
	}

	if(count==1)
		cout<<"Elephant\n";
	else if(count==2){

		for(i=1;i<=9;i++){
			if(arr[i]>0 && min==0)
				min=arr[i];
			else if(arr[i]>0 && mid==0)
				mid=arr[i];
		}
		//cout<<"min "<<min<<" max "<<max<<endl;
		if((min==2 && mid==4)||(min==4 && mid==2))
			cout<<"Elephant\n";
		else if((min==1)&&(mid==5))
			cout<<"Bear\n";
		else
			cout<<"Alien\n";
	}
	else if(count==3){
		for(i=1;i<=9;i++){
			if(arr[i]>0 && min==0)
				min=arr[i];
			else if(arr[i]>0 && mid==0)
				mid=arr[i];
			else if(arr[i]>0 && max==0)
				max=arr[i];
		}

		if(min==4||mid==4||max==4)
			cout<<"Bear\n";
		else 
			cout<<"Alien\n";
	}
	else{
		cout<<"Alien\n";
	}
}