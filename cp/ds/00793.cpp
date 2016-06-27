#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;
typedef std::vector<int> vi;
class UnionFind{
private: vi p,rank;
public:
	UnionFind(int N){
		rank.assign(N,0);p.assign(N,0);
		for (int i = 0; i < N; ++i) p[i]=i;
	}
	
	int findSet(int i){ return (p[i]==i) ? i:p[i]=findSet(p[i]); }
	bool isSameSet(int i,int j){return findSet(i)==findSet(j);}
	void unionSet(int i,int j){
		if(!isSameSet(i,j)){
			int x=findSet(i);int y=findSet(j);
			if(rank[x]>rank[y]) p[y]=x;
			else{
				p[x]=y;
				if(rank[x]==rank[y]) rank[y]++;
			}
		}
	}
};

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
	int t;
	cin>>t;
	string s;
	cin.ignore();
	cin.ignore();
	// cin>>s;
	// cout<<"s "<<s<<endl;
	while(t--){
		int n;
		cin>>n;
		// cout<<"n "<<n<<endl;
		UnionFind * u=new UnionFind(n);
		int success=0,unsuccess=0;
		// string s;
		// cin>>s;
		cin.ignore();
		char c;
		int a,b;
		while(std::getline (std::cin,s) && s.size()){
			// cout<<"s "<<s<<endl;
			sscanf(s.c_str(),"%c %d %d",&c,&a,&b);
			// cout<<"c "<<c<<"\t";
			// cout<<a<<" "<<b<<endl; 
			a--;b--;
			if(c=='q'){
				(u->isSameSet(a,b)==1) ? success++:unsuccess++; 
			}
			else if(c=='c'){
				u->unionSet(a,b);
			}
		}
		delete(u);
		cout<<success<<","<<unsuccess<<endl;
	}
	return 0;
}