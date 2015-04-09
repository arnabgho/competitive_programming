#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;

int main() {
	string s;
	cin>>s;
	int n,A=0,B=0,C=0;
	bool Ad=false,Bd=false,Cd=false;
	n=s.size();
	for (int i = 0; i < n; ++i){
		if(!Ad){
			if(s[i]=='|')
				A++;
			else if(s[i]=='+')
				Ad=true;
			continue;
		}
		if(Ad && !Bd){
			if(s[i]=='|')
				B++;
			else if(s[i]=='=')
				Bd=true;
			continue;
		}
		if(Ad && Bd){
			if(s[i]=='|')
				C++;
		}
	}	 
	bool pos=false;
	if(A+B==C){
		pos=true;
	}
	else if(A+B==C+2){
		if(A>B)
			A--;
		else
			B--;
		C++;
		pos=true;
	}
	else if(A+B+2==C){
		A++;
		C--;
		pos=true;
	}

	if(pos){
		// cout<<"A "<<A<<" B "<<B<<" C "<<C<<endl; 
		for (int i = 0; i < A; ++i)
		{
			cout<<"|";
		}
		cout<<"+";
		for (int i = 0; i < B; ++i)
		{
			cout<<"|";
		}
		cout<<"=";
		for (int i = 0; i < C; ++i)
		{
			cout<<"|";
		}
		cout<<endl;
	}
	else{
		cout<<"Impossible\n";
	}
	return 0;
}