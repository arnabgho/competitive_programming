#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
using namespace std;
#define INF 10000000000

int main(){

	long long int n;
	cin>>n;
	if(n%2==0) cout<<n/2<<endl;
	else cout<<-n+(n/2)<<endl;

	return 0;
}