#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<iostream>
#include<iomanip>
using namespace std;

long long int  array[200];
string s[200];
int main(){
	long long int num,mul,max,curr;
	int i,j,k,n;
	cin>>n;
	for(i=0;i<n;i++){
		cin>>s[i];
		num=0;
		if(s[i][0]!='1'){
			for(j=2;j<s[i].length();j++){
				num=num*10+(s[i][j]-'0');
			}
			for(j=s[i].length()-2;j<6;j++)
				num=num*10;
		}
		else
			num=1000000;
		array[i]=num;
		printf("%lld\n" , array[i]);		
	}	
	
	
	sort(array,array+n);
	max=array[n-1];
	for(i=2;i<=n;i++){
		curr=0;
		for(j=n-i;j<n;j++){
			mul=1;
			for(k=n-i;k<n;k++){
				if(k==j){
					mul=mul*array[j];
				}
				else
					mul=mul*(1000000-array[k]);
			}	
			curr+=mul;
			cout<<mul<<endl<<"----------"<<endl;
		}
		if(curr>max){
			max=curr;
		}
		else{
			break;
		}
	}	
	cout<<max<<endl;
	//printf("%.12lf\n",max);
	std::cout.precision(12);
	cout<<std::fixed<<max/1000000<<endl;
	return 0;
}
