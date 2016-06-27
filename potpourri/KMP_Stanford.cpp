#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>

using namespace std;

typedef std::vector<int> VI;

void buildTable(string &w , VI & t){
	t=VI(w.size());
	int i=2,j=0;
	t[0]=-1;t[1]=0;
	while(i<w.length()){
		if(w[i-1]==w[j]){t[i]=j+1;i++;j++;}
		else if(j>0) j=t[j];
		else{
			t[i]=0;i++;
		}
	}
	cout<<"HI Returned from buildTable\n";
}

int KMP(string &s,string &w){
	int m=0,i=0;
	VI t;
	buildTable(w,t);
	int s_size,w_size;
	cout<<"Table: "<<endl;
	s_size=s.size();
	w_size=w.size();
	for(int i=0;i<w_size;i++)
		cout<<t[i]<<endl;
	
	cout<<"s_size : "<<s_size<<endl;
	cout<<"w_size : "<<w_size<<endl;
	
	
	while((m+i)<s_size){
		//cout<<"Hi from KMP\n";
		if(w[i]==s[m+i]){
			i++;
			if(i==w_size)
				return m;	
		}
		else{
			m+=i-t[i];
			if(i>0) i=t[i];
		}
	}
	return s_size;
}



int main(){
	/*string s="The example above illustrates the general technique for assembling ";s+=
    "the table with a minimum of fuss. The principle is that of the overall search: ";s+=
    "most of the work was already done in getting to the current position, so very ";s+=
    "little needs to be done in leaving it. The only minor complication is that the ";s+=
    "logic which is correct late in the string erroneously gives non-proper ";s+=
    "substrings at the beginning. This necessitates some initialization code.";*/

   // string w="table";
    string s="ABC ABCDAB ABCDABCDABDE";
    string w="ABCDABD";
    int p=KMP(s,w);

    cout<<p<<" : "<<s.substr(p,w.length())<<" "<<w<<endl;

	return 0;
}