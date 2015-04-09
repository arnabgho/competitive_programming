 #include <bits/stdc++.h>
 #define _ ios_base::sync_with_stdio(0);cin.tie(0);
 
 using namespace std;
 
 int main() {
 	int a,b,s;
 	cin>>a>>b>>s;
 	int val=abs(a)+abs(b);
 	if(s>=val && (s-val)%2==0 )
 		cout<<"Yes\n";
 	else
 		cout<<"No\n";
 	return 0;
 }