#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;

// 0-> + ; 1-> - ; 2-> * ; 3-> /

bool DP[2][100000];
int off=40000;
typedef std::vector<int> vi;
string res[2][100000];
vi empty;
std::vector<int> p;

void clear(int cur){
	for (int i = 0; i < 100000; ++i)
	{
		DP[cur][i]=0;
		res[cur][i]="";
	}
}

int main() {
	int t;
	cin>>t;
	while(t--){
		p.clear();
		memset(DP,0,sizeof(DP));
		clear(0);clear(1);
		int k;
		cin>>k;
		k++;
		for (int i = 0; i <k ; ++i)
		{
			int x;cin>>x;p.push_back(x);
		}
		int cur,next;
		cur=0;
		next=1;
		DP[cur][off+p[0]]=1;
		for (int i = 0; i+1 <k-1 ; ++i)
		{
			for (int j = -32000; j <=32000 ; ++j)
			{
				if(!DP[cur][j+off]) continue;
				// try + 
				if( -32000<=j+p[i+1] && p[i+1]+j<=32000 ){
					res[next][j+off+p[i+1]]=res[cur][j+off]+'+';
					DP[next][j+off+p[i+1]]=1; 
				}	
				if( -32000<=j-p[i+1] && j-p[i+1]<=32000 ){
					if(!DP[next][j+off-p[i+1]])
						res[next][j+off-p[i+1]]=res[cur][j+off]+'-';
					DP[next][j+off-p[i+1]]=1; 
				}
				if( -32000<=j*p[i+1] && p[i+1]*j<=32000 ){
					if(!DP[next][off+p[i+1]*j] )
						res[next][off+j*p[i+1]]=res[cur][j+off]+'*';
					DP[next][off+p[i+1]*j]=1; 
				}
				if( j%p[i+1]==0 && -32000<=j/p[i+1] && j/p[i+1]<=32000 ){
					if(!DP[next][off+j/p[i+1]]) 
						res[next][off+j/p[i+1]]=res[cur][j+off]+'/';
					DP[next][off+j/p[i+1]]=1;
				}
			}
			clear(cur);
			cur=(cur+1)%2;
			next=(next+1)%2;
		}
		if(DP[cur][off+p[k-1]]) {
			string ans=res[cur][off+p[k-1]];
			for (int i = 0; i+1 < k-1; ++i)
			{
				cout<<p[i]<<ans[i];
			}
			cout<<p[k-2]<<"="<<p[k-1]<<endl;
		}
		else
			cout<<"NO EXPRESSION\n";
	}
	return 0;
}