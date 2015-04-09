#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;
typedef std::vector<int> vi;
std::vector<vi> res;

int f(vi v){
	int n=v.size();
	int val=0;
	for (int i = 0; i < n; ++i)
	{
		int minim=1e9;
		for (int j = i; j <n ; ++j)
		{
			//int x=*min_element(v.begin()+i,v.begin()+j);
			 int x=1e9;
			 for (int k = i; k <=j ; ++k)
			 {
			 	x=min(x,v[k]);
			 }
			//minim=min(minim,x);
			val+=x;
		}
		//val+=minim;
	}
	return val;
}

int main() {
	int n,m;
	cin>>n>>m;
	vi p;
	for (int i = 0; i < n; ++i)
	{
		p.push_back(i+1);
	}
	// cout<<" p.size() "<<p.size()<<endl;
	int maxim=0;
	do{
		maxim=max(maxim,f(p));
	}while(next_permutation(p.begin(),p.end()));
	int k=0;
	sort(p.begin(),p.end());
	vi ans;
	do{
		if(f(p)==maxim){
			k++;
		}
		if(k==m){
			ans=p;
			break;
		}
	}while(next_permutation(p.begin(),p.end()));

	for (int i = 0; i < n; ++i)
	{
		cout<<p[i]<<" ";
	}
	cout<<endl;
	return 0;
}

