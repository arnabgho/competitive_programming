#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

int p1[1000];
int p2[1000];
int main(){
	int i,n,n1,n2,x1,x2,ans;
	cin>>n;
	cin>>n1;
	for(i=0;i<n1;i++)
		cin>>p1[i];
	cin>>n2;
	for(i=0;i<n2;i++)
		cin>>p2[i];
	sort(p1,p1+n1);
	sort(p2,p2+n2);
	x1=0;
	x2=0;
	ans=1;
	for(i=1;i<=n;i++){
		if(p1[x1]==i && p2[x2]==i ){
			x1++;
			x2++;
		}
		else if(p1[x1]==i && p2[x2]!=i){
			x1++;
		}
		else if(p1[x1]!=i && p2[x2]==i){
			x2++;
		}
		else{
			ans=0;
			break;
		}
	}
	if(ans)
		cout<<"I become the guy."<<endl;
	else
		cout<<"Oh, my keyboard!"<<endl;

}
