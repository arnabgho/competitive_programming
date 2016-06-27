#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>


using namespace std;

int main()
{

	char ch,d;
	int	off,i,j;
	std::vector<string> v;
	string a="qwertyuiop";
	string b="asdfghjkl;";
	string c="zxcvbnm,./";
	v.push_back(a);
	v.push_back(b);
	v.push_back(c);
	cin>>ch;
	//cout<<"Hello \t"<<ch<<endl;
	if(ch=='R')
		off=-1;
	else
		off=1;
	//cin>>d;

	//cout<<"Off: "<<off<<endl;
	while(cin>>ch){
		//cout<<"\nHello inside \t"<<ch<<endl;
		if(off==1){
			//cout<<"Case 1"<<endl;
			for(i=0;i<3;i++){
				for(j=0;j<9;j++){
					if(v[i][j]==ch){
						cout<<v[i][j+1];
					}
				}
			}
		}
		else{
			//cout<<"Case -1"<<endl;
			for(i=0;i<3;i++){
				for(j=1;j<=9;j++){
					if(v[i][j]==ch){
						cout<<v[i][j-1];
					}
				}
			}
		}
	}
	cout<<endl;
	/* code */
	return 0;
}