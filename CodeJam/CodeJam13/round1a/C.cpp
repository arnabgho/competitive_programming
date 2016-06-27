#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;

int main() {
	int T;
	cin>>T;
	for (int cas = 1; cas <=T ; ++cas)
	{
		int R, N, M , K;
		cin>>R>>N>>M>>K;
		cout<<"Case #1:\n";
		for (int i = 0; i < R; ++i)
		{
			std::vector<int> prod(K);
			for (int i = 0; i < K; ++i)
			{
				cin>>prod[i];
			}
			std::vector<int> res(6,0);
			// check 3
			for (int i = 0; i < K; ++i)
			{
				if(prod[i]%3==0) res[3]=1;
			}
			for (int i = 0; i < K; ++i)
			{
				if(prod[i]%9==0) res[3]=2;
			}
			// check 5
			for (int i = 0; i < K; ++i)
			{
				if(prod[i]%5==0) res[5]=1;
			}
			for (int i = 0; i < K; ++i)
			{
				if(prod[i]%25==0) res[5]=2;
			}

			int numfound=0;
			accumulate(res.begin(),res.end(),numfound);
			
			if(numfound==2){
				for (int i = 0; i < K; ++i)
				{
					if(prod[i]%4==0)
						res[4]=1;
				}
				if(res[4]==0){
					for (int i = 0; i < K; ++i)
					{
						if(prod[i]%2==0)
							res[2]=1;
					}
				}
				if(res[2]+res[4]==0) res[2]=1;

			}
			else if(numfound==1){
				// check 16
				for (int i = 0; i <K ; ++i)
				{
					if(prod[i]%16==0)
						res[4]=2;
				}
				if(res[4]!=2){
					for (int i = 0; i <K ; ++i)
					{
						if(prod[i]%8==0){
							res[4]=1;
							res[2]=1;
						}
					}
					if(res[2]+res[4]!=2){
						for (int i = 0; i < K; ++i)
						{
							if(prod[i]%4 && ==0){
								res
							}
						}
					}
				}
			}

			for (int j = 2; j < 6; ++j)
			{
				for (int k = 0; k < res[j]; ++k)
				{
					cout<<j;
				}
			}
			cout<<endl;
		}
	}
	return 0;
}