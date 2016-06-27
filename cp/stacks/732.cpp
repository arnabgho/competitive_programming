#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;
std::set<string> result;

void dfs(stack<char> st,string s,string t,string res){
	//print 
	// cout<<"s "<<s<<" t "<<t<<endl; 
	if(t.size()==0){
		result.insert(res);
		return;
	}
	// push
	string temp;
	if(s.size()){
		st.push(s[0]);
		temp=s.size()>1 ?  s.substr(1) : "";
		dfs(st,temp,t,res+'i');
		st.pop();
	}
	//pop
	if(st.size() && st.top()==t[0]){
		temp=t.size()>1? t.substr(1):"";
		st.pop();
		dfs(st,s,temp,res+'o');
	}
}
int main() {
	string s,t;
	while(cin>>s){
		result.clear();
		cin>>t;
		stack<char> st;
		dfs(st,s,t,"");
		cout<<"[\n";
		for(auto r:result){
			cout<<r<<endl;
		}
		cout<<"]\n";	
	}
	return 0;
}