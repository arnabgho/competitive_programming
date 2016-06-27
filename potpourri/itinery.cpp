#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <map>
#include <set>
using namespace std;

std::vector<string> v;
std::set<string> mymap;
std::map<string, string> parent;
std::map<string, string> edge;
void initialise(){
	v.clear();
	mymap.clear();
	parent.clear();
	edge.clear();
}
int main(){
	//std::unordered_map<std::string>::const_iterator got;
	std::map<string,string>::iterator it;
	std::set<string>::iterator got;
	int i,j,t,n,size;
	string src="";
	string dest="";
	string temp="";
	cin>>t;
	for(int k=1;k<=t;k++){
		initialise();
		cin>>n;
		for(j=1;j<=n;j++){
			cin>>src;
			cin>>dest;
			edge[src]=dest;
			parent[dest]=src;
			got = mymap.find (src);
			if(got==mymap.end()){
				mymap.insert(src);
				v.push_back(src);
			}
			got=mymap.find(dest);
			if(got==mymap.end()){
				mymap.insert(dest);
				v.push_back(dest);
			}
		}
		size=v.size();
			for(i=0;i<size;i++){
				it=edge.find(v[i]);
				if(it==edge.end()){
					dest=v[i];
				}
				it=parent.find(v[i]);
				if(it==parent.end()){
					src=v[i];
				}
			}
			temp=src;
			cout<<"Case #"<<k<<": ";
			while(temp.compare(dest) != 0){
				it=edge.find(temp);
				cout<<it->first<<"-"<<it->second<<" ";
				temp=it->second;
			}
			cout<<endl;	

	}
	return 0;
}