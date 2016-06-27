#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;
std::vector<int> first;
std::vector<int> second;
int main() {
	int i,n,num;
	long long int first_score=0,sec_score=0;
	cin>>n;
	for(i=0;i<n;i++){
		cin>>num;
		if(num>=0){
			first_score+=num;
			first.push_back(num);
		}
		else{
			sec_score+=-num;
			second.push_back(-num);
		}
	}
	if(first_score>sec_score){
		cout<<"first\n";
	}
	else if(sec_score>first_score){
		cout<<"second\n";
	}
	else{
		if(first==second){
			if(first.size()%2==0)
				cout<<"second\n";
			else
				cout<<"first\n";
		}
		else if(first>second){
			cout<<"first\n";
		}
		else{
			cout<<"second\n";
		}
	}	
	return 0;
}