#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;

typedef pair<int,int> result;
std::vector<int> h(200);
std::vector<int> a(200);
std::vector<bool> h_state(200);
std::vector<bool> a_state(200);
std::vector<std::vector<int> > awayv(100);
std::vector<std::vector<int> > homev(100);
int main() {
	string home,away;
	cin>>home;
	cin>>away;
	int n,i,j,tim,num;
	char ch,card;
	cin>>n;
	for(i=0;i<n;i++){
		cin>>tim;
		cin>>ch;
		cin>>num;
		cin>>card;
		// cout<<"card "<<card<<" ch "<<ch<<endl;
		if(ch=='h'){
			if(card=='r'){
				h_state[num]=true;
				h[num]=tim;
				homev[tim].push_back(num);
			}
			else{
				if(h_state[num]){
					h[num]=tim;
					homev[tim].push_back(num);
				}
				else{
					h_state[num]=true;
				}
			}
		}
		else{
			if(card=='r'){
				a_state[num]=true;
				a[num]=tim;
				awayv[tim].push_back(num);
			}
			else{
				if(a_state[num]){
					h[num]=tim;
					awayv[tim].push_back(num);
				}
				else{
					a_state[num]=true;
				}
			}
		}
	}
	for(i=1;i<=90;i++){
		if(homev[i].size()>0){
			for(j=0;j<homev[i].size();j++){
				cout<<home<<" "<<homev[i][j]<<" "<<i<<endl;
			}
		}
		if(awayv[i].size()>0){
			for(j=0;j<awayv[i].size();j++){
				cout<<away<<" "<<awayv[i][j]<<" "<<i<<endl;
			}
		}
	}
	return 0;
}