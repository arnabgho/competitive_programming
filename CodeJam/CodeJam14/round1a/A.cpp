#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;
std::vector<string> cur;
std::vector<string> req;
std::vector<std::string> tokenizer( const std::string& p_pcstStr, char delim )  {
        std::vector<std::string> tokens;
        std::stringstream   mySstream( p_pcstStr );
        std::string         temp;

        while( getline( mySstream, temp, delim ) ) {
            tokens.push_back( temp );
        }

        return tokens;
    }

bool check(string l,int N){
	// cout<<"Check\n";
	std::vector<string> cur_ref=cur;
	std::vector<bool> used(N,0);
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < l.size(); ++j)
		{
			if(l[j]=='1'){
				if(cur_ref[i][j]=='0') cur_ref[i][j]='1';
				else cur_ref[i][j]='0';
			}
		}
	}

	// for (int i = 0; i < cur_ref.size(); ++i)
	// {
	// 	cout<<cur_ref[i]<<endl;
	// }
	// for (int i = 0; i < req.size(); ++i)
	// {
	// 	cout<<req[i]<<endl;
	// }
	// cout<<"------\n";
	// cout<<"used[0] "<<used[0]<<endl;
	// cout<<"Done\n";
	for(int i=0;i<cur_ref.size();i++){
		bool f=0;
		for(int j=0;j<cur_ref.size();j++){
			// cout<<"i "<<i<<" j "<<j<<endl;
			if(used[j]) continue;
			// cout<<"Hello\n";
			if(cur_ref[i].compare(req[j])==0 ){f=1;used[j]=1;break;}
		}
		if(!f) return 0;
	}
	return 1;
}

int main() {
	int T;
	cin>>T;
	for (int cas = 1; cas <=T ; ++cas)
	{
		int N,L;
		cin>>N>>L;
		string s;
		cur.clear();
		req.clear();
		for (int i = 0; i < N; ++i)
		{
			cin>>s;
			cur.push_back(s);
		}
		for (int i = 0; i < N; ++i)
		{
			cin>>s;
			req.push_back(s);
		}
		int mn=1e9;
		// cout<<"Hi\n";
		// for (int i = 0; i < cur.size(); ++i)
		// {
		// 	cout<<cur[i]<<endl;
		// }
		// for (int i = 0; i < cur.size(); ++i)
		// {
		// 	cout<<req[i]<<endl;
		// }
		// pos 0 of cur matches with pos 0...N-1 of req
		for(int i=0;i<N;i++){
			string l="";
			int count=0;
			for(int j=0;j<L;j++){
				if(cur[0][j]==req[i][j])
					l+='0';
				else{
					count++;
					l+='1';
				}
			}
			// cout<<"l "<<l<<endl;
			if(check(l,N)){
				// cout<<"Hi\n";
				mn=min(count,mn);
			}
		}
		if(mn<1e9)
			cout<<"Case #"<<cas<<": "<<mn<<endl;
		else
			cout<<"Case #"<<cas<<": NOT POSSIBLE\n";
	}
	return 0;
}