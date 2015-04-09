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

long long maxim(long long a,long long b){return a>b ? a:b;}

long long search(long long d,long long min,long long max){
	
	int mid=(min+max)/2;
	
	if(min==max && d-mid*(mid+1)<0)
		return 0;
	else if(min>max)
		return 0;	
	
	if(d-mid*(mid+1)>=0){
		return maxim(mid,search(d,mid+1,max));
	}
	else{
		return search(d,min,mid-1);
	}
}


class QuadraticLaw {
public:
	long long getTime(long long d) {
		return search(d,0,d);
	}
};


<%:testing-code%>
//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!