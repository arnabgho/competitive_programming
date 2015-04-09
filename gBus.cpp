#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
using namespace std;

int CITY[11111];
int ANS[11111];
vector <int> give;
void initialise(){
	give.clear();
	for(int i=0;i<11111;i++) {CITY[i]=0;ANS[i]=0;}
}

int main(){
	int j,i,cum,t,n,P,a,b,c;
	cin>>t;
	j=0;
	while(j<t){
		j++;
		cin>>n;
		for(i=1;i<=n;i++){
			cin>>a>>b;
			CITY[a]++;
			CITY[b+1]--;
		}
		cum=0;
		for(i=1;i<=10000;i++){
			cum+=CITY[i];
			ANS[i]=cum;
		}
		cin>>P;
		for(i=1;i<=P;i++){
			cin>>c;
			give.push_back(c);
		}
		cout<<"Case #"<<j<<": ";
		for(i=0;i<P;i++){
			cout<<ANS[give[i]]<<" ";
		}
		initialise();
		cout<<endl;
	}

	return 0;
}