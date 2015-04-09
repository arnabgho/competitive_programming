#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;
typedef std::vector<int> vi;
std::vector<vi> can_meet(200,std::vector<int> (200));
std::vector<int> winner(200);
std::vector<vi> win(200,std::vector<int> (200));
int n;

int meet(int i,int j){
	if((i+1)%n ==j || i==j ) return 1;

	if(can_meet[i][j]!=-1) return can_meet[i][j];

	for (int mid = (i+1)%n ; mid !=j ; mid=(mid+1)%n)
	{
		if(win[i][mid] || win[j][mid]){
			if(meet(i,mid) && meet(mid,j)){
				can_meet[i][j]=1;
				return 1;
			}
		}
	}

	can_meet[i][j]=0;
	return 0;
}

void solve(){
	int ans=0;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if(i==j || !win[i][j])
				continue;
			if(meet(i,j) && meet(j,i)){
				winner[ans++]=i+1;break;
			}
		}
	}

	cout<<ans<<endl;
	for (int i = 0; i < ans; ++i)
	{
		cout<<winner[i]<<endl;
	}
}


int main() {
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		for (int i = 0; i < n; ++i)
		{
			string s;
			cin>>s;
			for (int j = 0; j < n ; ++j)
			{
				win[i][j]=s[j]-'0';
			}
		}
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				can_meet[i][j]=-1;
			}
		}
		solve();
	}
	return 0;
}