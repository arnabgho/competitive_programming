#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;

std::vector<int> v;

int f(){
	int score=0;
	for (int i = 0; i < v.size(); ++i)
	{
		score+= (v[i]<=i);
	}
	return score;
}

int main() {
	int T,G,N;
	cin>>T;
	for (int cas = 1; cas <=T ; ++cas)
	{
		cin>>N;
		v.clear();
		for (int i = 0; i < N; ++i)
		{
			int x;
			cin>>x;
			v.push_back(x);
		}
		if(f()>=(472+500)/2)
			cout<<"Case #"<<cas<<": GOOD"<<endl;
		else
			cout<<"Case #"<<cas<<": BAD"<<endl;
	}
	return 0;
}