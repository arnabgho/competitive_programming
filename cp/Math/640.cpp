#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;



int dp[1000010];

int sumDig(int n){
	int ans=0;
	while(n>0){
		ans+=n%10;
		n/=10;
	}
	return ans;
}

int main() {
	std::clock_t start;
    double duration;

    start = std::clock();
	memset(dp,-1,sizeof(dp));
	for (int i = 1; i <=1000000 ; ++i)
	{
		if(dp[i]!=-1) continue;
		printf("%d\n",i);
		int num=i+sumDig(i);
		int prev=i;
		while(num<=1000000){
			if(dp[num]!=-1) break;
			dp[num]=prev;
			prev=num;
			num=num+sumDig(num);
		}
	}
	duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;

    // std::cout<<"printf: "<< duration <<'\n';
	return 0;
}