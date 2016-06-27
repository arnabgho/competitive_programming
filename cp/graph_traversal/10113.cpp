#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;

map<string,int> ID;
typedef pair<int,int> pi;
typedef pair<int,pi> ppi;

int gcd(int a,int b){
	if(a==0)
		return b;
	return gcd(b%a,a);
}

typedef std::vector<ppi> vp;
std::vector<vp> G(100);
std::vector<bool> vis(100);
pi res;
void dfs(int s,int t,pi val){
	if(s==t){
		vis[s]=1;
		res=val;
	}
	if(vis[s])
		return;
	vis[s]=1;
	for (auto adj:G[s])
	{
		int v=adj.first;
		int a=adj.second.first;
		int b=adj.second.second;
		int g=gcd(val.first*a,val.second*b);
		pi newval=pi( (val.first*a)/g,(val.second*b)/g);
		dfs(v,t,newval);
	}
}

std::vector<std::string> tokenizer( const std::string& p_pcstStr, char delim )  {
        std::vector<std::string> tokens;
        std::stringstream   mySstream( p_pcstStr );
        std::string         temp;

        while( getline( mySstream, temp, delim ) ) {
            tokens.push_back( temp );
        }

        return tokens;
    } 

int main() {
	string s;
	int st=0;
	getline(cin,s);
	while(tokenizer(s,' ').size()>1){
		int a,b;
		string x,y;
		char equal;
		string res_left,res_right;
		std::vector<string> v=tokenizer(s,' ');
		if(v[0].compare("!")==0){
			x=v[2];
			y=v[5];
			a=stoi(v[1]);
			b=stoi(v[4]);
			// cout<<"a "<<a<<" b "<<b<<endl;
			if(!ID.count(x))
				ID[x]=st++;
			if(!ID.count(y))
				ID[y]=st++;
			G[ID[x]].push_back(ppi(ID[y],pi(a,b)));
			G[ID[y]].push_back(ppi(ID[x],pi(b,a)));
		}
		else{
			fill(vis.begin(),vis.end(),0);
			x=v[1];y=v[3];
			if(!ID.count(x) || !ID.count(y)){res_left="?";res_right="?";}
			else{
				res=pi(-1,-1);
				dfs(ID[x],ID[y],pi(1,1));
				if(res!=pi(-1,-1)){
					int g=gcd(res.first,res.second);
					res_left=to_string(res.first/g);
					res_right=to_string(res.second/g);
				}
				else{res_left="?";res_right="?";}
			}
			cout<<res_left<<" "<<x<<" = "<<res_right<<" "<<y<<endl;			
		}
		getline(cin,s);
	}
	return 0;
}