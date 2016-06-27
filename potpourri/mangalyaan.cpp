#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

int astro[1000];
int main(){
	int i,t,n,thresh,ans;
	cin>>t;
	while(t--){
		ans=0;
		cin>>n>>thresh;
		for(i=1;i<=n;i++){
			cin>>astro[i];
			if(astro[i]>=thresh)
				ans++;
		}
		cout<<ans<<endl;
	}

	return 0;
}