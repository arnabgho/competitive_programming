#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;
int countInv(std::vector<int> v){
	int n=v.size();
	int ans=0;
	for (int i = 0; i <n ; ++i)
	{
		for (int j = i+1; j < n; ++j)
		{
			if(v[i]>v[j]) 
				ans++;
		}
	}
	return ans;
}

double simulate(std::vector<int> v,int k){
	if(k==0)
		return countInv(v);
	double val=0;
	int n=v.size();
	for (int i = 0; i < n; ++i)
	{
		for (int j = i; j < n; ++j)
		{
			std::vector<int> v_rev=v;
			reverse(v_rev.begin()+i,v_rev.begin()+j+1);
			val+=simulate(v_rev,k-1);/* code */
		}
	}
	return val;
}


int main() {
	std::vector<int> v;
	int n,k;
	cin>>n>>k;
	for (int i = 0; i < n; ++i)
	{
		int x;
		cin>>x;
		v.push_back(x);
	}
	double den=(n*(n+1))/2;
	den=pow(den,k);
	double num=simulate(v,k);
	double res=num/den;
	printf("%.20lf\n", res);
	return 0;
}