#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <string>
using namespace std;

vector<int> convert(111111);
// int mod(int x){ return x>0 ? x:-x;}

int main(){
	string s="";
	int i,n,pos,left,right,l_c,r_c,ans,ans1,fin;
	cin>>n;
	cin>>pos;
	cin>>s;
	n--;
	pos--;
	left=0;
	right=n;
	while(left<=right){
		l_c=s[left]-97;
		r_c=s[right]-97;
		ans=l_c-r_c;
		ans1=r_c-l_c;
		if(ans<0){
			fin=min(26+ans,ans1);
		}
		else if(ans1<0){
			fin=min(26+ans1,ans);
		}
		else{
			fin=0;
		}
		convert[left]=fin;
		convert[right]=fin;
		left++;right--;
	}
	// for(i=0;i<n;i++){
	// 	cout<<"i: "<<convert[i]<<endl;
	// }

	int mid=n/2,tot_left=0,tot_right=0,final=0,len_left,len_right;
	int left_end=0,right_end=mid;
	if(pos>n/2 ){
		if(n%2==0)
			pos=2*mid-pos;
		else
			pos=2*mid-pos+1;
	}

	for(i=0;i<pos;i++){
		tot_left+=convert[i];
	}
	for(i=pos+1;i<=mid;i++){
		tot_right+=convert[i];
	}
	// cout<<"tot_left: "<<tot_left<<" tot_right : "<<tot_right<<endl;
	
	while(convert[left_end]==0 && left_end<pos){left_end++;}
	while(convert[right_end]==0 && right_end>pos){right_end--;}

	// cout<<"left_end: "<<left_end<<" right_end : "<<right_end<<endl;
	// cout<<"pos: "<<pos<<endl;

	final=convert[pos]+tot_left+tot_right+right_end-left_end;
	// cout<<"final :"<<final<<endl;
	len_left=pos-left_end;
	len_right=right_end-pos;
	// cout<<"len_left "<<len_left<<" len_right : "<<len_right<<endl;
	if(len_left<len_right){
		final+=len_left;
	}
	else{
		final+=len_right;
	}
	cout<<final<<endl;
	return 0;
}