#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;
int b[400];
string a[400];

int digsum(string x){
	int val=0;
	for (int i = 0; i < x.size(); ++i)
	{
		val+=x[i]-'0';
	}
	return val;
}

string nextHigher(string x,int k){
	cout<<"nextHigher x "<<x<<" k "<<k<<endl;
	reverse(x.begin(),x.end());
	cout<<"reverse x "<<x<<endl;
	string res="";
	int ndig=x.size();
	if(digsum(x)==k)
		return x;
	if(k>9*ndig){
		res="9";
		while(k>9){
			k-=9;
			char ch=('0'+k);
			res=res+ch;
		}	
	}
	else{
		string zeros="0";
		string nines="9";
		bool f=0;
		for (int i = 0; i <ndig && !f; ++i)
		{
			int d=x[i]-'0';
			int maxim,minim;
			if(i==0){
				maxim=digsum(nines+x.substr(i+1));
				minim=digsum(x);
				if(minim<=k && k<=maxim){
					f=1;
					cout<<"d "<<d<<endl;
					for (int l = d; l <=9 ; ++l)
					{
						char ch=('0'+l);
						if(digsum(ch+x.substr(i+1))==k)
							res=ch+x.substr(i+1);
						cout<<"l "<<l<<"res "<<res<<endl;
					}
				}
			}	
			else{
				for (int l = d; l <=9 && !f  ; ++l)
				{
					char ch=('0'+l);
					maxim=digsum(nines+ch+x.substr(i+2));
					minim=digsum(zeros+ch+x.substr(i+2));
					if(minim<=l && l<=maxim){
						f=1;
						string tx=x.substr(0,i);
						cout<<"tx "<<tx<<endl;	
						reverse(tx.begin(),tx.end());
						string rem=x.substr(i+1);
						string temp=nextHigher(tx,k-digsum(rem));
						reverse(temp.begin(),temp.end());
						res=temp+rem;
					}
				}
			}
			zeros+="0";
			nines+="9";
		}
	}
	reverse(res.begin(),res.end());
	while(res[0]=='0'){
		res=res.substr(1);
	}
	return res;
}

int main() {
	int n;
	cin>>n;
	for (int i = 1; i <= n; ++i)
	{
		cin>>b[i];
	}
	a[1]=std::to_string(b[1]);
	for (int i = 2; i <=n ; ++i)
	{
		a[i]=nextHigher(a[i-1],b[i]);
	}
	for (int i = 1; i <=n ; ++i)
	{
		cout<<a[i]<<endl;
	}
	return 0;
}