#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;

std::map<int, string> DP;
typedef pair<int,int> pi;
bool getBit(int n,int i){
	return (n>>i)&1 !=0;
}
int main() {
	DP[0]="1111110";
	DP[1]="0110000";
	DP[2]="1101101";
	DP[3]="1111001";
	DP[4]="0110011";
	DP[5]="1011011";
	DP[6]="1011111";
	DP[7]="1110000";
	DP[8]="1111111";
	DP[9]="1111011";
	
	int t;
	cin>>t;
	for(int cas=1;cas<=t;cas++){
		int n;
		cin>>n;
		std::vector<string> v;
		for (int i = 0; i < n; ++i)
		{
			string s;
			cin>>s;
			v.push_back(s);
		}
		std::vector<pi> ans;
		for (int mask = 0; mask < (1<<7) ; ++mask)
		{
			for (int start = 0; start <10 ; start++)
			{
				bool pos=1;
				for (int i = 0; i < min(10,n); ++i)
				{
					int val=(start-i+100)%10;
					string s=DP[val];
					for (int j = 0; j < 7; ++j)
					{
						if(!getBit(mask,j) && s[j]=='1')
							s[j]='0';
					}
					if((s.compare(v[i]))!=0)
						pos=0;
				}
				if(pos)
					ans.push_back(pi(mask,start));
			}
		}
		string res="ERROR!";
		if(ans.size()==1){
			int mask=ans[0].first;
			int start=ans[0].second;
			int val=(start-(n)+100)%10;
			res=DP[val];
			for (int j = 0; j < 7; ++j){
				if(!getBit(mask,j) && res[j]=='1')
					res[j]='0';
			}
		}
		cout<<"Case #"<<cas<<": "<<res<<endl;
	}
	return 0;
}