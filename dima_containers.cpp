#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;

std::vector<int> v;
std::vector<int> ref;
std::vector<bool> maxim;
std::vector<string> in;
std::vector<string> out;
void compute(){
	int n;
	n=v.size();
	ref=v;
	if(n<3){
		for (int i = 0; i < n; ++i)
		{
			cout<<in[i]<<endl;/* code */
		}
		if(n>0)
			cout<<n<<" ";
		else cout<<n<<endl;
		for (int i = 0; i < n; ++i)
		{
			if(i!=n-1)
				cout<<out[i]<<" ";
			else cout<<out[i]<<endl;
		}
	}
	else{
		sort(v.rbegin(), v.rend());int one=v[0];int two=v[1];int three=v[2];int numtaken=0;
		for (int i = 0; i < ref.size(); ++i)
		{
			if(ref[i]==one || ref[i]==two || ref[i]==three)/* code */
				maxim[i]=1;
		}
		for (int i = 0; i < ref.size(); ++i)
		{
			if(numtaken==0){
				cout<<in[0]<<endl;
				if(maxim[i]){
					numtaken++;
				}
			}	
			else if(numtaken==1){
				if(maxim[i]){
					cout<<in[1]<<endl;
					numtaken++;
				}
				else{
					cout<<in[3]<<endl;
				}
			}
			else if(numtaken==2){
				if(maxim[i]){
					cout<<in[2]<<endl;
					numtaken++;
				}
				else{
					cout<<in[3]<<endl;
				}
			}
			else if(numtaken==3){
				cout<<in[3]<<endl;
			}
		}
		cout<<"3 popStack popQueue popFront\n";
	}	
	v.clear();ref.clear();maxim.clear();
}

int main() {
	int n,num;
	in.push_back("pushStack");in.push_back("pushQueue");in.push_back("pushFront");in.push_back("pushBack");
	out.push_back("popStack");out.push_back("popQueue");out.push_back("popFront");out.push_back("popBack");
	cin>>n;
	for (int i = 0; i < n; ++i)
	{
		cin>>num;
		if(num>0){ v.push_back(num); maxim.push_back(false);}
		else {
			compute();
		}
	}
	return 0;
}