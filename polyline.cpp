#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;

int main() {
	int n,m;
	cin>>n>>m;
	if(n!=0 && m!=0){
		cout<<0<<" "<<0<<endl;
		cout<<n<<" "<<m<<endl;
		if(n>m){
			cout<<0<<" "<<m<<endl;
			cout<<n<<" "<<0<<endl;
		}
		else{
			cout<<n<<" "<<0<<endl;			
			cout<<0<<" "<<m<<endl;
		}
	}
	else if(n==0){
		cout<<0<<" "<<1<<endl;
		cout<<0<<" "<<m<<endl;
		cout<<0<<" "<<0<<endl;
		cout<<0<<" "<<m-1<<endl; 
	}
	else if(m==0){
		cout<<1<<" "<<0<<endl;
		cout<<n<<" "<<0<<endl;
		cout<<0<<" "<<0<<endl;
		cout<<n-1<<" "<<0<<endl; 
	}
	return 0;
}