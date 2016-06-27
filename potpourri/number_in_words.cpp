#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include <iostream>
using namespace std;




string big[3]={"Hundred","Thousand","Million"};
string  digits[10]={"Zero","One","Two","Three","Four","Five","Six","Seven","Eight","Nine"};
string  teens[9]={"Eleven","Twelve","Thirteen","Fourteen","Fifteen","Sixteen","Seventeen","Eighteen","Nineteen"};
string  tens[9]={"Ten","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety"};


string number_to_string(int n){
	string res="";
	int temp,dig;
	if(n==0)
		return res=digits[0];
	dig=0;
	temp=n;
	while(temp>0){
		temp/=10;
		dig++;
	}
	if(dig==1){
		res=digits[n]+" ";
		return res;
	}
	if(dig==2){
		if(n%10==0){
			res=tens[n/10-1]+" ";
			return res;
		}
		else{
			if(n/10-1>0){
				res=tens[n/10-1]+" "+digits[n%10]+" ";
				return res;
			}
			else if(n/10==1){
				res=teens[n%10-1]+"";
				return res;
			}
		}
	}
	if(dig==3){
		res=number_to_string(n%100);
		if(n%100==0){
			res=digits[n/100]+" Hundred ";
			return res;
		}
		else{
			res=digits[n/100]+" Hundred "+res;
			return res;
		}
	}
}	
int main(int argc, char const *argv[])
{
	
	int n,a,b,c;
	cin>>n;
	a=n%1000;
	n/=1000;
	b=n%1000;
	n/=1000;
	c=n%1000;
	string first,second,third,result;
	first="";
	second="";
	third="";
	result="";

	result+=(c==0)? "":(number_to_string(c)+" Million ");

	result+=(b==0)? "":( number_to_string(b)+" Thousand ");

	result+=(a==0)? "":( number_to_string(a));

	if(a==0 && b==0 && c==0)
		result=digits[0];

	cout<<result<<endl;

	/* code */
	return 0;
}