#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;

std::vector<string> v;
typedef pair<char,int> pi;
int f(string s1,string s2){
	std::vector<pi> Streak1,Streak2;
	int c=0;
	for (int i = 0; i < s1.size(); ++i)
	{	
		c++;
		if(i==s1.size()-1 || s1[i+1]!=s1[i]){
			Streak1.push_back(pi(s1[i],c));
			c=0;
		}
	}
	c=0;
	for (int i = 0; i < s2.size(); ++i)
	{
		c++;
		if(i==s2.size()-1 || s2[i+1]!=s2[i]){
			Streak2.push_back(pi(s2[i],c));
			c=0;
		}
	}
	if(Streak1.size()!=Streak2.size()) return 1e9;
	int val=0;
	for (int i = 0; i < Streak1.size(); ++i)
	{
		// cout<<"Streak1.first "<<Streak1[i].first<<" Streak1.second "<<Streak1[i].second<<endl;
		// cout<<"Streak2.first "<<Streak2[i].first<<" Streak2.second "<<Streak2[i].second<<endl;
		if(Streak1[i].first!=Streak2[i].first) return 1e9;
		val+=abs(Streak1[i].second-Streak2[i].second);
	}
	return val;
}

int median(std::vector<int> med){
	sort(med.begin(),med.end());
	// cout<<"----------------\n";
	
	// cout<<endl;
	if(med.size()==1)
		return med[0];
	int n=med.size();
	if(n%2==0)
		return (med[n/2]+med[n/2-1])/2;
	return med[n/2];
}

bool valid=1;
string findMean(){
	vector<std::vector<pi> > Streaks;
	for (int j = 0; j < v.size(); ++j)
	{
		std::vector<pi> Streak;
		int c=0;
		string s=v[j];
		for (int i = 0; i < s.size(); ++i)
		{	
			c++;
			if(i==s.size()-1 || s[i+1]!=s[i]){
				Streak.push_back(pi(s[i],c));
				c=0;
			}
		}
		Streaks.push_back(Streak);
	}
	// cout<<"Streaks completed\n";
	for (int i = 1; i < Streaks.size(); ++i)
	{
		if(Streaks[0].size()!=Streaks[i].size()){valid=0;return "";}
		for (int j = 0; j < Streaks[0].size(); ++j)
		{
			if(Streaks[0][j].first!=Streaks[i][j].first){valid=0;return "";}
		}
	}
	// cout<<"Computation Done\n";
	std::vector<pi> res;
	res=Streaks[0];
	
	std::vector<int> med;
	for (int j = 0; j <res.size() ; ++j)
	{
		for (int i = 0; i < Streaks.size(); ++i)
		{
			med.push_back(Streaks[i][j].second);
		}
		res[j].second=median(med);
		// cout<<"median - "<<res[j].second<<endl;
		// cout<<"---------\n";
	}

	string ret="";
	for (int i = 0; i < res.size(); ++i)
	{
		for (int j = 0; j < res[i].second; ++j)
		{
			ret+=res[i].first;
		}
	}
	return ret;
}

int main() {
	int T,N;
	cin>>T;
	for (int cas = 1; cas <=T; ++cas)
	{
		cin>>N;
		v.clear();
		string s;
		valid=1;
		for (int i = 0; i < N; ++i)
		{
			cin>>s;
			v.push_back(s);
		}
		string M=findMean();
		// cout<<"M "<<M<<endl;
		if(!valid) cout<<"Case #"<<cas<<": Fegla Won\n";
		else{
			int mn=0;
			for (int i = 0; i <N ; ++i)
			{
				mn+=f(v[i],M);	
			}	
			cout<<"Case #"<<cas<<": "<<mn<<endl;
		}
	}
	return 0;
}