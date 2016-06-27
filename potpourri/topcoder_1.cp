#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

vector<int> num(101,0);

class SortishDiv2 {
public:
	int compute(int sortedness,vector<int> &seq,int zeros,int n){
		int i,j,count,pos;
		count=0;
		pos=0;
		if(zeros==0){
			for(i=0;i<n;i++){
				for(j=i+1;j<n;j++){
					if(seq[i]<seq[j])
						count++;
				}
			}
			cout<<"Count: "<<count<<endl;
			return count==sortedness;
		}
		else{
			fill(num.begin(),num.end(),0);
			for(i=0;i<n-1;i++){
				if(!pos && seq[i]==0){
					pos=i;
				}
				num[seq[i]]=1;
			}
			for(i=1;i<=n;i++){
				if(num[i]==0){
					seq[pos]=i;
					count+=compute(sortedness,seq,zeros-1,n);
					seq[pos]=0;
				}			
			}
			fill(num.begin(),num.end(),0);
			return count;
		}
			
	}

	int ways(int sortedness, vector <int> seq) {
		int i,n,zeros=0;
		n=seq.size();
		for(i=0;i<n;i++){
			if(seq[i]==0)
				zeros++;
		}
		return compute(sortedness,seq,zeros,n);
	}
};



//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!