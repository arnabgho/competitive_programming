#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;

int main() {
	string s;
	cin>>s;
	map<int,string> ref;
	ref[0]="zero";ref[10]="ten"; 	  	 
	ref[1]= 	"one" 	;ref[11]= 	"eleven"; 	  	 
	ref[2]= 	"two"; 	ref[12]=	"twelve" ;ref[20]="twenty";
	ref[3]= 	"three" ;	ref[13]= 	"thirteen"; 	ref[30]= 	"thirty";
	ref[4]= 	"four" 	;ref[14] =	"fourteen" ;	ref[40]= 	"forty";
	ref[5]= 	"five" 	;ref[15]= 	"fifteen";	ref[50]= "fifty";
	ref[6]= 	"six" 	;ref[16]= 	"sixteen"; 	ref[60]= 	"sixty";
	ref[7]=		"seven" ;ref[17]= 	"seventeen"; 	ref[70]= 	"seventy";
	ref[8]= 	"eight" ;ref[18]= 	"eighteen"; 	ref[80]= 	"eighty";
	ref[9]= 	"nine" 	;ref[19]= 	"nineteen"; 	ref[90]= 	"ninety";
	if(s.size()==1)
		cout<<ref[s[0]-'0']<<endl;
	else{
		// int num=stoi(s);
		int num=10*(s[0]-'0')+s[1]-'0';
		// cout<<"num "<<num<<endl;
		if(ref.count(num)!=0)
			cout<<ref[num]<<endl;
		else{
			int d=num%10;
			num-=d;
			cout<<ref[num]<<"-"<<ref[d]<<endl;
		}
	}
	return 0;
}