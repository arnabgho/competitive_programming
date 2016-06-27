#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

int X[100][2];
int Z[100][2];

int main(){
	int i,j,k,p,q,l,r,found,ans;

	cin>>p>>q>>l>>r;

	for(i=1;i<=p;i++){
		cin>>Z[i][0]>>Z[i][1];
	}

	for(i=1;i<=q;i++){
		cin>>X[i][0]>>X[i][1];
	}
	ans=0;
	for(k=l;k<=r;k++){
		found=0;
		for(i=1;i<=p && !found ;i++){
			for(j=1;j<=q && !found;j++){
				if(!((X[j][1]+k<Z[i][0]) ||(X[j][0]+k>Z[i][1]) )){
					found=1;
					break;
				}
			}
		}
		//cout<<"k= "<<k<<" found = "<<found<<endl;
		ans+=found;
	}

	cout<<ans<<endl;
	return 0;
}