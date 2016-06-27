#include <stdio.h>
#include <algorithm>
#include <string>
#include <iostream>
#include <stdlib.h>

using namespace std;

bool overlaps(long long int x,long long int y,long long int S,long long int E){

	return (y>S && y<E) || (x>S && x<E) ;
}

int main(){

	long long int i,t,n,S,E,x,y,pos;
	cin>>t;
	while(t--){
		pos=1;
		cin>>S>>E;
		cin>>n;
		for(i=1;i<=n;i++){
			cin>>x>>y;
			pos=pos && !overlaps(x,y,S,E);


			// cout<<"X: "<<x<<" ";
			// cout<<"Y: "<<y<<" ";
			// cout<<"E: "<<E<<" ";
			// cout<<"S: "<<S<<" \n";

			// cout<<overlaps(x,y,S,E)<<endl;
		}
		if(pos)
			cout<<"YES\n";
		else
			cout<<"NO\n";
	}

	return 0;
}