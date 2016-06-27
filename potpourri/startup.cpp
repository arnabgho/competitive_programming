#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <unordered_map>

using namespace std;

std::unordered_map < char,int > check={{'A',1},{'H',2},{'I',3},{'M',4},{'O',5},{'T',6},{'U',7},{'V',8},{'W',9},{'X',10},{'Y',11}};

int main(){
	string s1="";
	string rev="";
	cin>>s1;
	int pos=1;
	int left=0;
	int right=s1.size()-1;
	
	while(left<=right){
		if(s1[left]!=s1[right]){
			pos=0;
			break;
		}
		else{
			unordered_map<char,int>::const_iterator it=check.find(s1[left]);
			if(it==check.end()){
				pos=0;
				break;
			}
		}
		left++;
		right--;
	}

	if(pos)
		cout<<"YES\n";
	else
		cout<<"NO\n";
	return 0;
}