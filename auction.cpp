#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;

double E[10][11111];
std::vector<int> L(6);
std::vector<int> R(6);

int main() {
	int n;
	cin>>n;
	for (int i = 1; i <= n; ++i)
	{
		cin>>L[i];
		cin>>R[i];/* code */
	}

	for (int i = 1; i <=n ; ++i)
	{
		for (int sec_best = L[i]; sec_best <= R[i] ; ++sec_best)
		{
			double ans=0;
			for (int j = 1; j <=n ; ++j)
			{
				if(j==i) continue;
				if(R[j]<sec_best) continue;
				//ans+=1.0*(R[j]-sec_best+1)/(1.0*(R[j]-L[j]+1));
				double val;
				if(L[j]<sec_best)
					val=1.0*(R[j]-sec_best)/(1.0*(R[j]-L[j]+1));
				else
					val=1;
				for (int k = 1; k <=n ; ++k)
				{	
					if(k==i || k==j) continue;
					if(L[k]>sec_best){
					 val=0;break;
					}
					if(R[k]>sec_best)
						val*=1.0*(sec_best-L[k])/(1.0*(R[k]-L[k]+1));
					else
						val*=1;
				}
				ans+=val;
			}
			E[i][sec_best]=ans*(1.0/(R[i]-L[i]+1));
			cout<<E[i][sec_best]<<" ";
		}
		cout<<endl;
	}
	double EXP=0;
	for (int i = 1; i <=n ; ++i)
	{
		//cout<<"Hi \n";
		//cout<<"L "<<L[i]<<" R "<<R[i]<<endl;;
		for (int j = L[i]; j <=R[i] ; ++j)
		{
			//cout<<" j "<<j<<endl;
			EXP+=j*E[i][j];
		}
	}
	cout<<EXP<<endl;
	return 0;
}