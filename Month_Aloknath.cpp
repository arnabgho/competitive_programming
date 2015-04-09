#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;
typedef long long int LL;
std::vector<LL> numbers;
std::vector<LL> rnumbers;
std::vector<LL> temp;
bool getBit(LL n,LL i){
	return ((n & (1LL<<i))!=0);
}
int main() {
	LL t,n,k,num,req,pos,posf,posb,sum,left,right,numfound,s,temp_sum,found,i,j;
	cin>>t;
	while(t--){
		cin>>n>>k;
		pos=1;
		sum=0;
		for (i = 0; i < n; ++i)
		{
			cin>>num;/* code */
			numbers.push_back(num);
			sum+=num;
		}
		rnumbers=numbers;
		if(sum%k !=0){
			pos=0;
		}
		if(pos){
			req=sum/k;
			sort(numbers.begin(),numbers.end());
			numfound=0;
			for(int iter=0;iter<k;iter++){
				s=numbers.size();
				found=0;
				for(i=1;i<(1<<s);i++){
					std::vector<bool> bits_used(s,false);
					temp_sum=0;
					for(j=0;j<s;j++){
						if(getBit(i,j)){
							temp_sum+=numbers[j];
							bits_used[j]=true;
							// cout<<"bit used "<<j<<endl;
						}
					}
					if (temp_sum==req)
					{
						 // cout<<"req "<<req<<" temp_sum "<<temp_sum<<" iter "<<iter<<endl;
						numfound++;
						// for (int i = 0; i < numbers.size(); ++i)
						// {
						// 	cout<<"before "<<numbers[i]<<endl;/* code */
						// }
						for(int k=0;k<s;k++){
							if(!bits_used[k]){ temp.push_back(numbers[k]);}
						}
						numbers=temp;found++;
						// for (int i = 0; i < numbers.size(); ++i)
						// {
						// 	cout<<"after "<<numbers[i]<<endl;/* code */
						// }
						temp.clear();break;
					}
				}
				if(!found) break;
			}	
			if (numfound!=k)
			{
				posf=0;/* code */
			}
			numbers=rnumbers;
			sort(numbers.rbegin(),numbers.rend());
			numfound=0;
			for(int iter=0;iter<k;iter++){
				s=numbers.size();
				found=0;
				for(i=1;i<(1<<s);i++){
					std::vector<bool> bits_used(s,false);
					temp_sum=0;
					for(j=0;j<s;j++){
						if(getBit(i,j)){
							temp_sum+=numbers[j];
							bits_used[j]=true;
							// cout<<"bit used "<<j<<endl;
						}
					}
					if (temp_sum==req)
					{
						 // cout<<"req "<<req<<" temp_sum "<<temp_sum<<" iter "<<iter<<endl;
						numfound++;
						// for (int i = 0; i < numbers.size(); ++i)
						// {
						// 	cout<<"before "<<numbers[i]<<endl;/* code */
						// }
						for(int k=0;k<s;k++){
							if(!bits_used[k]){ temp.push_back(numbers[k]);}
						}
						numbers=temp;found++;
						// for (int i = 0; i < numbers.size(); ++i)
						// {
						// 	cout<<"after "<<numbers[i]<<endl;/* code */
						// }
						temp.clear();break;
					}
				}
				if(!found) break;
			}	
			if (numfound!=k)
			{
				posb=0;/* code */
			}
			pos=(posf||posb);
		}	
		if(pos) cout<<"yes\n";
		else cout<<"no\n";
		numbers.clear();
		rnumbers.clear();
	}
	return 0;
}