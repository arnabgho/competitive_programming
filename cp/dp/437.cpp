#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;

struct block
{
	int a,b,c;
	block(int x,int y,int z) : a(x),b(y),c(z){}
};



struct TestStruct {
        int id;
        TestStruct() : id(42)
        {
        }
};


bool operator <(const block& x, const block& y) {
    return std::tie(x.a, x.b, x.c) < std::tie(y.a, y.b, y.c);
}


int LIS(std::vector<block> v){
	std::vector<int> maxim(v.size(),0);
	maxim[0]=v[0].c;
	int MAX=0;
	int n=v.size();
	for (int i = 1; i <n ; ++i)
	{
		for (int j = 0; j <i ; ++j)
		{
			if(v[i].a<v[j].a && v[i].b<v[j].b || v[i].a<v[j].b && v[i].b<v[j].a){
				maxim[i]=max(maxim[i],maxim[j]+v[i].c);
				MAX=max(MAX,maxim[i]);
			}
		}
	}
	return MAX;
}


int main() {
	int n;
	cin>>n;
	int c=1;
	while(n!=0){
		std::vector<block> v;
		for (int i = 0; i < n; ++i)
		{
			std::vector<int> dims(3);
			for (int j = 0; j < 3; ++j)
			{
				cin>>dims[j];
			}
			sort(dims.begin(),dims.end());
			do{
				v.push_back(block(dims[0],dims[1],dims[2]));
			}while(next_permutation(dims.begin(),dims.end()));
		}
		sort(v.rbegin(),v.rend());
		cout<<"Case "<<c<<": maximum height = "<<LIS(v)<<endl;
		cin>>n;
		c++;
	}
	return 0;
}