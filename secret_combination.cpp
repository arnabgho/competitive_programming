#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;

std::vector<int> one,two;
int main() {
	int n;
	cin>>n;
	std::vector<int> best(n,9);
	string s="";
	cin>>s;
	for (int i = 0; i < n; ++i)
	{
		one.push_back(s[i]-'0');
	}
	for (int i = 0; i < 10; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			one[j]=(one[j]+1)%10;
			// cout<<"one[j] "<<one[j];
		}
		for (int j = 0; j < n; ++j)
		{
			int last=one[n-1];
			for (int k = n-1; k > 0;k--)
			{
				one[k]=one[k-1];
			}
			one[0]=last;
			int pos=0;
			bool found=false;
			while(pos<n){
				if(one[pos]==best[pos])
					pos++;
				else{
					found=true;break;
				}
			} 

			if(found){
				if(one[pos]<best[pos]){
					for (int cop = 0; cop < n; ++cop)
					{
						best[cop]=one[cop];
					}
				}
			}
		}
	}
	for (int i = 0; i < n; ++i)
	{
		cout<<best[i];
	}
	cout<<endl;
	return 0;
}