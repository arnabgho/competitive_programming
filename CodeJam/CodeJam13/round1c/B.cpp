#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;

int main() {
	int T;
	cin>>T;
	for (int cas = 1; cas <=T ; ++cas)
	{
		int x,y;
		cin>>x>>y;
		// first complete x 
		string res="";

		int start=0;
		int turn=1;
		while(start!=x){
			if(turn%2==0){
				start+=turn;
				res+='E';
			}
			else{
				start-=turn;
				res+='W';
			}
			turn++;
		}
		start=0;
		while(start!=y){
			if(y<0){
				if(turn%2==0){
					start+=turn;
					res+='N';
				}
				else{
					start-=turn;
					res+='S';
				}
			}
			else{
				if(turn%2==1){
					start+=turn;
					res+='N';
				}
				else{
					start-=turn;
					res+='S';
				}
			}	
			turn++;
		}
		cout<<"Case #"<<cas<<": "<<res<<endl;
	}
	return 0;
}