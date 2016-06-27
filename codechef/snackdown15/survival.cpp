#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;
std::vector<int> votes(111111,0);
std::vector<int> freq(111111,0);
int main() {
	int T;
	cin>>T;
	while(T--){
		fill(votes.begin(),votes.end(),0);
		fill(freq.begin(),freq.end(),0);
		int A,D,n;
		cin>>n;
		D=n-1;
		A=n;
		for (int i = 1; i <= n-2; ++i)
		{
			int x;
			cin>>x;
			votes[x]++;
		}
		for (int i = 1; i <= n-2; ++i)
		{
			int x;
			cin>>x;
			votes[x]++;
		}
		int mx=-1,mxpos,mnpos,mn=1e9;
		for (int i = 1; i <=n ; ++i)
		{
			// mn=min(mn,votes[i]);
			// mx=max(mx,votes[i]);
			if(mn>votes[i]){
				mn=votes[i];
				mnpos=i;
			}
			if(mx<votes[i]){
				mx=votes[i];
				mxpos=i;
			}
			freq[votes[i]]++;
		}
		std::vector<int> vA(2,0);
		std::vector<int> vD(2,0);
		if(votes[D]!=mn && votes[A]!=mn && votes[D]!=mx && votes[A]!=mx){
			vD[0]=mxpos;
			vD[1]=A;
			vA[0]=mxpos;
			vD[1]=D;
			cout<<"both\n";
		}
		else if(votes[D]==mn && votes[A]==mn){
			if(freq[votes[D]]>2){
				cout<<"both\n";
			}
			else if(freq[votes[D]]==2){
				cout<<"none\n";
			}
			vD[0]=A;
			vD[1]=mxpos;
			vA[0]=D;
			vA[1]=mxpos;
		}
		else if(votes[D]==mx && votes[A]==mx){
			if(freq[votes[D]-1]!=0){
				int pos=0;
				for (int i = 1; i <=n-2 ; ++i)
				{
					if(votes[D]-1==votes[i]){
						pos=i;
						break;
					}
				}
				cout<<"both\n"; 
			}

		}



		for (int i = 0; i <2 ; ++i) cout<<vD[i]<<" ";
		cout<<endl;
		for (int i = 0; i <2 ; ++i) cout<<vA[i]<<" ";
		cout<<endl;
	}
	return 0;
}