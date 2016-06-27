#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;
std::vector<char> v;
std::vector<string> words;
std::vector<int> len;
bool cmp(string a,string b){
	return a.size()<b.size();
}
int main() {

	string word;
	ifstream myfile ("words");
	if (myfile.is_open())
  	{
    while ( getline (myfile,word) )
    {
      // cout << line << '\n';
    	std::transform(word.begin(), word.end(), word.begin(), ::tolower);	
    	words.push_back(word);
    }
    myfile.close();
 	 }
 	 sort(words.begin(), words.end(),cmp);
 	 for(int i=0;i<words.size();i++){
 	 	len.push_back(words[i].size());
 	 }
	cout<<"Enter The String\n";
	string s="";
	cin>>s;
	int i,n=s.size();
	std::transform(s.begin(), s.end(), s.begin(), ::tolower);	
	bool found=false;
	sort(s.begin(),s.end());
	std::vector<int>::iterator low,up,it;
	low=std::lower_bound (len.begin(), len.end(), n); //          ^
  	up= std::upper_bound (len.begin(), len.end(), n); 
  	int low_pos,up_pos;
  	low_pos=low-len.begin();
  	up_pos=up-len.begin();	
	 do{
	 	for(i=low_pos;i<=up_pos;i++){
	 		if(!s.compare(words[i])){
	 			cout<<s<<endl;
	 			// found=1;break;
	 		}
	 	}	
	 	
	 	// if(found) break;
	 }while( /*!found &&*/ next_permutation(s.begin(),s.end()));
	return 0;
}