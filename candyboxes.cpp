#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;

std::vector<double> A;
std::vector<double> temp;

bool check(std::vector<double> v){
	double range=v[3]-v[0];
	double mean=(v[0]+v[1]+v[2]+v[3])/4;
	double median=(v[1]+v[2])/2;
	return (mean==median && range==mean);
}
int main() {
	double i,n,a,j;
	cin>>n;
	for(i=0;i<n;i++) {
		cin>>a;
		A.push_back(a);
	}	
	sort(A.begin(),A.end());
	if(n==0){
		cout<<"YES\n1\n1\n3\n3\n";
	}
	if(n==4){
		if(check(A)) cout<<"YES\n";
		else cout<<"NO\n";
	}
	if(n==1){
		cout<<"YES\n";
		cout<<a<<endl;
		cout<<3*a<<endl;
		cout<<3*a<<endl;		
	}
	double found=0;	
	if(n==3){
		for(i=1;i<=2000 &&!found;i++){
			temp=A;
			temp.push_back(i);
			sort(temp.begin(),temp.end());
			if(check(temp)) {cout<<"YES\n"<<i<<endl;found++;break;}
		}
		if(!found) cout<<"NO\n";
	}
	found=0;
	if(n==2){
		for(i=1;i<=2000 && !found;i++){
			for(j=1;j<=2000 && !found;j++){
				temp=A;
				temp.push_back(i);
				temp.push_back(j);
				sort(temp.begin(),temp.end());
				if(check(temp)) {cout<<"YES\n"<<i<<endl<<j<<endl;found++;break;}
			}
		}
		if(!found) cout<<"NO\n";
	}
	return 0;
}