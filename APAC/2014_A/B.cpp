#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;
int A[100][100];
int F[100][100];
vector<int> compress(std::vector<int> v){
	std::vector<int> res;
	for (int i = 0; i< v.size(); ++i)
	{
		if(i+1==v.size()){
			res.push_back(v[i]);
			break;
		}
		if(v[i]==v[i+1])
			res.push_back(2*v[i++]);
		else
			res.push_back(v[i]);
	}
	return res;
}
int main() {
	int t;cin>>t;
	for (int cas = 1; cas <=t ; ++cas)
	{
		memset(A,0,sizeof(A));
		memset(F,0,sizeof(F));
		int n;
		cin>>n;
		string dir;
		cin>>dir;
		for (int i = 0; i <n ; ++i)
		{
			for (int j = 0; j <n ; ++j)
			{
				cin>>A[i][j];
			}
		}
		if(dir.compare("right")==0){
			for (int i = 0; i < n; ++i)
			{
				std::vector<int> v,res;
				for (int j = 0; j <n ; ++j)
				{
					if(A[i][j]>0) v.push_back(A[i][j]);
				}
				reverse(v.begin(),v.end());
				res=compress(v);
				for (int j = res.size()-1; j >=0 ; --j)
				{
					F[i][n-1-j]=res[j];
				}
			}
		}
		else if(dir.compare("left")==0){
			for (int i = 0; i < n; ++i)
			{
				std::vector<int> v,res;
				for (int j = 0; j <n ; ++j)
				{
					if(A[i][j]>0) v.push_back(A[i][j]);
				}
				res=compress(v);
				for (int j = 0; j <res.size() ; ++j)
				{
					F[i][j]=res[j];
				}
			}
		}
		else if(dir.compare("up")==0){
			for (int j = 0; j < n; ++j)
			{
				std::vector<int> v,res;
				for (int i = 0; i <n ; ++i)
				{
					if(A[i][j]>0) v.push_back(A[i][j]);
				}
				res=compress(v);
				for (int i = 0; i <res.size() ; ++i)
				{
					F[i][j]=res[i];
				}
			}
		}
		else if(dir.compare("down")==0){
			for (int j = 0; j < n; ++j)
			{
				std::vector<int> v,res;
				for (int i = 0; i <n ; ++i)
				{
					if(A[i][j]>0) v.push_back(A[i][j]);
				}
				reverse(v.begin(), v.end());
				res=compress(v);
				for (int i = res.size()-1; i >=0 ; --i)
				{
					F[n-1-i][j]=res[i];
				}
			}
		}
		printf("Case #%d:\n",cas );
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j <n ; ++j)
			{
				cout<<F[i][j]<<" ";
			}
			cout<<endl;
		}
	}
	return 0;
}