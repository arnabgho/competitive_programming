#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;
//0 -
//1 +
int main(){
	string s1,s2;
	cin>>s1;
	cin>>s2;
	double tot,act,res;
	int size,p,pos_orig,k,pos_new,mask,temp,i,j,n;
	size=s1.size();
	pos_orig=0;
	for(i=0;i<size;i++){
		if(s1[i]=='+')
			pos_orig++;
		else if(s1[i]=='-')
			pos_orig--;
	}

	//cout<<"pos_orig: "<<pos_orig<<endl;
	k=0;
	pos_new=0;
	res=0.0;
	for(i=0;i<size;i++){
		if(s2[i]=='+')
			pos_new++;
		else if(s2[i]=='-')
			pos_new--;
		else if(s2[i]=='?')
			k++;			
	}
	//cout<<"pos_new: "<<pos_new<<endl;
	//cout<<"k: "<<k<<endl;
	mask=1<<k;
	tot=mask;
	if(k>0){
	act=0.0;
	for(j=0;j<mask;j++){
		temp=j;
		p=0;
		n=0;
		for(i=0;i<k;i++){
			if(temp%2==1)
				p++;
			else
				n++;
			temp=temp>>1;
		}
		//cout<<"p: "<<p<<endl;
		//cout<<"n: "<<n<<endl;
		if(pos_new+p-n==pos_orig)
			act++;
	}
	//cout<<"act: "<<act<<endl;
	std::cout.precision(10);
	cout<<act/tot<<endl;
	}
	else{
		if(pos_new==pos_orig)
			cout<<"1"<<endl;
		else
			cout<<"0"<<endl;
	}
	return 0;

}