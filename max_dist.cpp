#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string>

using namespace std;


bool sync_with_stdio (bool sync = true);

std::vector<int> v(26);
int main()
{
	int i,n,t,len,num;
	string s="";
	cin>>t;
	while(t--){
		cin>>s;
		num=0;
		n=s.size();
		fill(v.begin(),v.end(),0);
		for(i=0;i<n;i++){
			if(v[s[i]-97]==0) {
				num++;
				v[s[i]-97]++;
			}
		}
		cout<<num<<endl;
	}

	/* code */
	return 0;
}