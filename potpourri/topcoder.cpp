#include<stdio.h>
#include<stdlib.h>
#include<vector>
#include<algorithm>

using namespace std;

int min(int a,int b){return a<b ? a:b;}
int max(int a,int b){return a>b ? a:b;}

class SlimeXSlimonadeTycoon{
	public:

		int sell(vector <int> morning, vector <int> customers, int stale_limit){
			int ans=0,i,j,temp,cust;
			int n=morning.size();
			for(i=0;i<n;i++){	
				cust=customers[i];
				for(j=max(i-stale_limit+1,0);j<=i;j++){
					
					temp=min(morning[j],cust);
					cust-=temp;
					morning[j]-=temp;
					ans+=temp;
				}	
			}
			return ans;

		}
};
