#include <stdio.h>
#include <iostream>
#include <algorithm>

#define INF 100000000000;

using namespace std;

typedef pair<long long int,long long int> PII;



int main(){

	int n;	
	long long int x,y;
	cin>>n;
	PII left_bot;
	PII left_top;
	PII right_bot;
	PII right_top;

	left_bot->first=INF;
	left_bot->second=INF;
	left_top->first=INF;
	left_top->second=INF;	
	right_bot->first=INF;
	right_bot->second=INF;
	right_top->first=INF;
	right_top->second=INF;
	while(n--){
		cin>>x>>y;

		if(x>right_top->first && y>right_top->second){
			right_top->first=x;
			right_top->second=y;
		}
		if(x<left_bot->first && y<left_bot->second){
			left_bot->first=x;
			left_bot->second=y;
		}

		if(x>=left_bot->first && y<=right_top->second){
			right_top->first=x;
			right_top->second=y;
		}
	}

	return 0;
}