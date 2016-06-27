#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;

int main() {
	int T;
	cin>>T;
	for (int cas = 1; cas <=T ; ++cas)
	{
		int A,B,K,res=0;
		cin>>A>>B>>K;
		for (int i = 0; i < A; ++i)
		{
			for (int j = 0; j < B; ++j)
			{
				int val=i & j;
				if(val<K) res++;
 			}
		}
		cout<<"Case #"<<cas<<": "<<res<<endl;
	}
	return 0;
}