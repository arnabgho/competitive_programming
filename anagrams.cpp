#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;
int f[300][26];
int t1[26],t2[26];
int main() {
	int t;
	cin>>t;
	while(t--){
		string s;
		cin>>s;
		int n=s.size();
		memset(f,0,sizeof(f));
		f[0][s[0]-'a']=1;
		for (int i = 1; i < n; ++i)
		{
			for(int j=0;j<26;j++){
				f[i][j]=f[i-1][j];
			}
			f[i][s[i]-'a']=f[i-1][s[i]-'a']+1;
		}

		int ans=0;

		for (int l = 0; l <n ; ++l)
		{
			for(int i=0;i<=n-l;i++){
				// cout<<"i "<<i<<" l "<<l<<endl;
				for (int j = 0; j < 26; ++j)
				{
					if(i==0){
						t1[j]=f[i+l][j];
					}
					else{
						t1[j]=f[i+l][j]-f[i-1][j];
					}
					// cout<<t1[j]<<" ";
				}
				// cout<<endl;
				for(int j=i+1;j<=n-l;j++){
					for (int k = 0; k < 26; ++k)
					{
						if(j==0){
							t2[k]=f[j+l][k];
						}
						else{
							t2[k]=f[j+l][k]-f[j-1][k];
						}
					}
					bool pos=true;
					for (int k = 0; k <26 && pos ; ++k)
					{
						if(t1[k]!=t2[k])
							pos=false;
					}
					ans+=pos;
				}
				
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}