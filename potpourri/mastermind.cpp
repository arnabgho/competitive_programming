#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;
typedef std::vector<int> vi;
const int inf =1e9;
int main() {
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		std::vector<vi> P(n+1,vi(m+1));
		std::vector<vi> B(n+1,vi(m+1));
		vi row(n+1);
		for (int i = 1; i <=n ; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				cin>>P[i][j];
			}
		}
		for (int i = 1; i <=n ; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				cin>>B[i][j];
			}
		}
		row[n]=*(min_element(P[n].begin(),P[n].begin()+m));
		// cout<<"row[n] "<<row[n]<<endl;
		for (int i = n-1; i >=0 ; --i)
		{
			int power=inf;
			for(int j=0;j<m;j++){
				int k=min(row[i+1],B[i][j]);
				int temp=row[i+1]-k+P[i][j];
				if(temp<=0)
					continue;
				else
					power=min(power,temp);
			}
			row[i]=power;
		}
		// cout<<"row\n";
		// for (int i = 0; i <=n; ++i)
		// {
		// 	cout<<row[i]<<" ";
		// }
		cout<<row[1]<<endl;
	}
	return 0;
}