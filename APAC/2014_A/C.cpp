#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;
typedef pair<int,int> pi;
typedef pair<pi,int> ppi;

map<string,int> DP;

std::vector<std::string> tokenizer( const std::string& p_pcstStr, char delim )  {
        std::vector<std::string> tokens;
        std::stringstream   mySstream( p_pcstStr );
        std::string         temp;

        while( getline( mySstream, temp, delim ) ) {
            tokens.push_back( temp );
        }

        return tokens;
    } 

int power(int a,int b){
	if(b==0) return 1;
	return a*power(a,b-1);
}

std::vector<ppi> given;
int main() {
	int t;
	cin>>t;
	for (int cas = 1; cas <=t ; ++cas)
	{
		int n,q;
		cin>>n;
		int ID=0;
		DP.clear();
		given.clear();
		for (int i = 0; i < n; ++i)
		{
			string s;
			std::vector<string> v1,v2;
			cin>>s;
			v1=tokenizer(s,'=');
			int sum=stoi(v1[1]);
			v2=tokenizer(v1[0],'+');
			int id0,id1;
			if(DP.count(v2[0])) id0=DP[v2[0]];
			else {id0=ID++;DP[v2[0]]=id0;}

			if(DP.count(v2[1])) id1=DP[v2[1]];
			else {id1=ID++;DP[v2[1]]=id1;}

			given.push_back(ppi(pi(id0,id1),sum));
		}
		cin>>q;
		cout<<"Case #"<<cas<<":\n";
		for (int i = 0; i < q; ++i)
		{
			string s;
			cin>>s;
			std::vector<string> v;
			v=tokenizer(s,'+');
			int id0,id1;
			if(!DP.count(v[0]) || !DP.count(v[1])){
				continue;
			}
			id0=DP[v[0]];
			id1=DP[v[1]];
			int ans=-1;
			for (int mask = 0; mask < power(3,n) ; ++mask)
			{
				int val=0;
				int tempmask=mask;
				std::vector<int> coefficients(ID,0);
				for (int bit = 0; bit < n; ++bit)
				{
					if(mask%3==1){
						val+=given[bit].second;
						coefficients[given[bit].first.first]++;
						coefficients[given[bit].first.second]++;
					}
					if(mask%3==2){
						val-=given[bit].second;
						coefficients[given[bit].first.first]--;
						coefficients[given[bit].first.second]--;
					}
					mask/=3;
				}
				mask=tempmask;
				// cout<<"mask "<<mask<<" val "<<val<<endl;
				bool pos=1;
				// for (int i = 0; i <ID; ++i)
				// {
				// 	cout<<coefficients[i]<<" ";
				// }
				// cout<<endl;
				for (int k = 0; k < ID ; ++k)
				{
					if(k==id0 && coefficients[k]!=1)
						pos=0;
					else if(k==id1 && coefficients[k]!=1)
						pos=0;
					else if( k!=id0 && k!=id1 && coefficients[k]!=0)
						pos=0;
				}
				if(pos) ans=val;
			}
			if(ans!=-1)
				cout<<s<<"="<<ans<<endl;
		}
	}
	return 0;
}