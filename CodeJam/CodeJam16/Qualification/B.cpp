#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;
typedef long long ll;
typedef pair<ll,ll> pi;
const double eps=1e-9;

std::vector<int> remove_trailing_ones(std::vector<int> st){
	int cur=-1;
	for (int i = st.size(); i >=0 ; --i)
	{
		if(st[i]==0){
			cur=i;
			break;
		}
	}
	if (cur==-1) return st;
	std::vector<int> res;
	for (int i = 0; i <=cur ; ++i)
	{
		res.push_back(st[i]);
	}
	return res;
}

int compute(std::vector<int> st){
	int cur=-1;							//Stores the position of the first 0
	cout<<"------------------------------\n";	
	for(auto s:st)
		cout<<"s "<<s<<endl;
	cout<<"------------------------------\n";	
	st=remove_trailing_ones(st);
	if(st.size()==0) return 0;
	for (int i = 0; i <st.size() ; ++i)
	{
		if(st[i]==0){
			cur=i;
			break;
		}
	}
	std::vector<int> temp;
	for (int i = cur; i >=0 ; --i)
	{
		temp.push_back((st[i]+1)%2);
	}
	return 1+compute(temp);
}


int main() {
	ll t;
	cin>>t;
	for (ll cas = 1; cas <= t; ++cas)
	{
		/* code */
		string s;
		cin>>s;
		std::vector<int> st;
		for (int i = 0; i < s.size(); ++i)
		{
			if(s[i]=='+')
				st.push_back(1);
			else
				st.push_back(0);
		}


		ll ans=0;
		ans=compute(st);
		printf("Case #%lld: %lld\n",cas,ans);
	}
	return 0;
}