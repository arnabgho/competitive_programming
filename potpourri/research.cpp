#include<stdio.h>
#include<iostream>
#include<map>

using namespace std;

int main(){
	long long int i,n,s,curr,sum,test,val;
	std::map<long long int , long long int> prefix;
	sum=0;
	
	val=0;
	cin>>n>>s;
		prefix[0]=1;
	//cout<<prefix[0];	
	for(i=1;i<=n;i++){

		cin>>curr;
		sum+=curr;
		test=sum-s;
		
		if(prefix.count(test)>0){
			val+=prefix.find(test)->second;
			//cout<<"test:"<<test<<"val:"<<val<<endl;
		}
		prefix[sum]+=1;
	}
	cout<<val<<endl;
	return 0;
}
