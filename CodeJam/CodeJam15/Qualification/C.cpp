#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;
// i->2 , j->3 , k->4
map<char,int> mp;


int val(int i,int j){
	int sgn= i*j >0 ? 1:-1;
	i=abs(i);
	j=abs(j);

	if(i==1 && j==1){
		return sgn*(1);
	}
	if(i==1 && j==2){
		return sgn*(2);
	}
	else if(i==1 && j==3){
		return sgn*(3);
	}
	else if(i==1 && j==4){
		return sgn*(4);
	}

	if(i==2 && j==1){
		return sgn*(2);
	}
	else if(i==2 && j==2){
		return sgn*(-1);
	}
	else if(i==2 && j==3){
		return sgn*(4);
	}
	else if(i==2 && j==4 ){
		return sgn*(-3);
	}

	else if(i==3 && j==1){
		return sgn*(3);
	}

	else if(i==3 && j==2){
		return sgn*(-4);
	}
	else if(i==3 && j==3){
		return sgn*(-1);
	}
	else if(i==3 && j==4 ){
		return sgn*(2);
	}


	else if(i==4 && j==1){
		return sgn*(4);
	}

	else if(i==4 && j==2){
		return sgn*(3);
	}
	else if(i==4 && j==3){
		return sgn*(-2);
	}
	else if(i==4 && j==4 ){
		return sgn*(-1);
	}
}
int main() {
	mp['i']=2;
	mp['j']=3;
	mp['k']=4;

	int t;
	cin>>t;
	for (int cas = 1; cas <=t ; ++cas)
	{
		int l,x;
		string s;
		cin>>l>>x;
		cin>>s;
		string t=s;
		for (int i = 0; i <x ; ++i)
		{
			s+=t;
		}
		std::vector<int> cum(l*x+10);
		cum[0]=mp[s[0]];
		for (int i = 1; i < l*x; ++i)
		{
			cum[i]=val(cum[i-1],mp[s[i]]);
		}
		// for (int i = 0; i < l*x; ++i)
		// {
		// 	cout<<cum[i]<<" ";
		// }
		// cout<<endl;

		string Y="YES";
		string N="NO";
		string ans;
		if(cum[l*x-1]!=-1){
			ans=N;
			cout<<"Case #"<<cas<<": "<<ans<<endl;
			continue;
		}
		// int pos1=-1;
		// for (int i = 0; i <l*x ; ++i)
		// {
		// 	if(cum[i]==2){
		// 		pos1=i;break;
		// 	}
		// }
		// int pos2=-1;
		// for(int i=pos1+1;i<l*x;++i){
		// 	if(cum[i]==4){
		// 		pos2=i;break;
		// 	}
		// }

		bool pos=0;
		for(int i=0;i<l*x;i++){
			for(int j=i+1;j<l*x;j++){
				if(cum[i]==2 && cum[j]==4)
					pos=1;
			}
		}

		if(pos)
			ans=Y;
		else ans=N;
		
		cout<<"Case #"<<cas<<": "<<ans<<endl;
	}
	return 0;
}