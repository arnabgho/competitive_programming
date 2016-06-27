#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

int main(){

	string s1="+------------------------+"; 
	string c1="|#.#.#.#.#.#.#.#.#.#.#.|D|)";
	string c2="|#.#.#.#.#.#.#.#.#.#.#.|.|";
	string c3="|#.......................|";
	string c4="|#.#.#.#.#.#.#.#.#.#.#.|.|)";
	string s6="+------------------------+";
	int n,i,mod_2,mod_1,mod_0;
	cin>>n;
	mod_2=3;
	mod_1=3;
	mod_0=3;
	for(i=1;i<=n;i++){
		if(i==1){
			c1[1]='O';
			continue;
		}
		else if(i==2){
			c2[1]='O';
			continue;
		}
		else if(i==3){
			c3[1]='O';
			continue;
		}
		else if(i==4){
			c4[1]='O';
			continue;
		}

		if(i%3==2){
			c1[mod_2++]='O';
			mod_2++;
		}
		else if(i%3==0){
			c2[mod_0++]='O';
			mod_0++;
		}
		else if(i%3==1){
			c4[mod_1++]='O';
			mod_1++;
		}
	}
	cout<<s1<<endl;
	cout<<c1<<endl;
	cout<<c2<<endl;
	cout<<c3<<endl;
	cout<<c4<<endl;
	cout<<s6<<endl;	
}