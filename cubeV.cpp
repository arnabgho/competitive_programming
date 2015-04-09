#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <map>
#include <set>
using namespace std;

typedef std::vector<int> VI;
std::vector<VI> ARR;
void initialise(){
	ARR.clear();
}

int main(){
	int t,i,n,j,k,s;
	cin>>t;
	for(k=1;k<=t;k++){
		cin>>n;
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				cin>>s;
				ARR[i].push_back(s);
			}
		}
		
	}
	return 0;
}