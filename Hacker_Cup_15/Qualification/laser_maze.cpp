#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;
const int inf=1e8;
typedef pair<int,int> pi;
typedef pair<pi,int> ppi;
int mod[4][200][200];
char maze[200][200];

queue<ppi> myQ;
int m,n;

bool isValid(int i,int j){
	return 0<=i && i<m && 0<=j && j<n;
}

bool checkValid(int i,int j){
	return maze[i][j]=='.' || maze[i][j]=='S'|| maze[i][j]=='G';
}

int main() {
	int t;
	bool found;
	cin>>t;
	for (int cas = 1; cas <=t; ++cas)
	{
		int si,sj,gi,gj;
		string s;
		cin>>m>>n;
		for (int i = 0; i <m; ++i)
		{
			cin>>s;
			for (int j = 0; j < n; ++j)
			{
				maze[i][j]=s[j];
				if(s[j]=='.' || s[j]=='S' || s[j]=='G'){
					mod[0][i][j]=0;
					mod[1][i][j]=0;
					mod[2][i][j]=0;
					mod[3][i][j]=0;
				}
				else{
					mod[0][i][j]=-1;
					mod[1][i][j]=-1;
					mod[2][i][j]=-1;
					mod[3][i][j]=-1;
				}
				if(s[j]=='S'){
					si=i;sj=j;
				}
				if(s[j]=='G'){
					gi=i;gj=j;
				}
			}
		}
		for (int i = 0; i <m; ++i)
		{
			for (int j = 0; j <n ; ++j)
			{
				if(maze[i][j]=='>'){
					found=false;
					for(int k=j+1;k<n && !found;k++){
						if(!checkValid(i,k)){
							found=true;break;
						}
						mod[0][i][k]=-1;
					}
					found=false;
					for (int k = i+1; k <m && !found ; k++)
					{
						if(!checkValid(k,j)){
							found=true;break;
						}
						mod[1][k][j]=-1;
					}
					found=false;
					for(int k=j-1;k>=0 && !found;k--){
						if(!checkValid(i,k)){
							found=true;break;
						}
						mod[2][i][k]=-1;
					}
					found=false;
					for (int k = i-1; k >=0 && !found ; k--)
					{
						if(!checkValid(k,j)){
							found=true;break;
						}
						mod[3][k][j]=-1;
					}
				}

				if(maze[i][j]=='<'){
					// cout<<"Hi < \n--------------\n";
					found=false;
					for(int k=j+1;k<n && !found;k++){
						if(!checkValid(i,k)){
							found=true;break;
						}
						mod[2][i][k]=-1;
					}
					found=false;
					for (int k = i+1; k <m && !found ; k++)
					{
						if(!checkValid(k,j)){
							found=true;break;
						}
						mod[3][k][j]=-1;
					}
					found=false;
					for(int k=j-1;k>=0 && !found;k--){
						if(!checkValid(i,k)){
							// cout<<"j "<<j<<endl;
							// cout<<"Found i "<<i<<" k "<<k<<endl;
							found=true;break;
						}
						mod[0][i][k]=-1;
					}
					found=false;
					for (int k = i-1; k >=0 && !found ; k--)
					{
						if(!checkValid(k,j)){
							found=true;break;
						}
						mod[1][k][j]=-1;
					}
				}

				if(maze[i][j]=='v'){
					found=false;
					for(int k=j+1;k<n && !found;k++){
						if(!checkValid(i,k)){
							found=true;break;
						}
						mod[3][i][k]=-1;
					}
					found=false;
					for (int k = i+1; k <m && !found ; k++)
					{
						if(!checkValid(k,j)){
							found=true;break;
						}
						mod[0][k][j]=-1;
					}
					found=false;
					for(int k=j-1;k>=0 && !found;k--){
						if(!checkValid(i,k)){
							found=true;break;
						}
						mod[1][i][k]=-1;
					}
					found=false;
					for (int k = i-1; k >=0 && !found ; k--)
					{
						if(!checkValid(k,j)){
							found=true;break;
						}
						mod[2][k][j]=-1;
					}
				}

				if(maze[i][j]=='^'){
					found=false;
					for(int k=j+1;k<n && !found;k++){
						if(!checkValid(i,k)){
							found=true;break;
						}
						mod[1][i][k]=-1;
					}
					found=false;
					for (int k = i+1; k <m && !found ; k++)
					{
						if(!checkValid(k,j)){
							found=true;break;
						}
						mod[2][k][j]=-1;
					}
					found=false;
					for(int k=j-1;k>=0 && !found;k--){
						if(!checkValid(i,k)){
							found=true;break;
						}
						mod[3][i][k]=-1;
					}
					found=false;
					for (int k = i-1; k >=0 && !found ; k--)
					{
						if(!checkValid(k,j)){
							found=true;break;
						}
						mod[0][k][j]=-1;
					}
				}

			}
		}
		// cout<<"mod 0\n";
		// for (int i = 0; i < m; ++i)
		// {
		// 	for (int j = 0; j < n; ++j)
		// 	{
		// 		cout<<mod[0][i][j]<<" ";
		// 	}
		// 	cout<<endl;
		// }

		// cout<<"mod 1\n";
		// for (int i = 0; i < m; ++i)
		// {
		// 	for (int j = 0; j < n; ++j)
		// 	{
		// 		cout<<mod[1][i][j]<<" ";
		// 	}
		// 	cout<<endl;
		// }

		// cout<<"mod 2\n";
		// for (int i = 0; i < m; ++i)
		// {
		// 	for (int j = 0; j < n; ++j)
		// 	{
		// 		cout<<mod[2][i][j]<<" ";
		// 	}
		// 	cout<<endl;
		// }

		// cout<<"mod 3\n";
		// for (int i = 0; i < m; ++i)
		// {
		// 	for (int j = 0; j < n; ++j)
		// 	{
		// 		cout<<mod[3][i][j]<<" ";
		// 	}
		// 	cout<<endl;
		// }

		
		int ans=-1;
		pi temp=make_pair(si,sj);
		myQ.push(make_pair(temp,0));
		bool foundA=false;
		// cout<<"si "<<si<<" sj "<<sj<<endl;
		// cout<<"gi "<<gi<<" gj "<<gj<<endl;
		while(!myQ.empty() && !foundA){
			pi u=myQ.front().first;
			int tim=myQ.front().second;
			int nT=(tim+1)%4;
			int x=u.first;int y=u.second;
			// cout<<"x "<<x<<" y "<<y<<endl;
			// cout<<"Time "<<tim<<endl;
			myQ.pop();
			for (int i = -1; i <=1 && !foundA; ++i)
			{
				for (int j = -1; j <=1 && !foundA; ++j)
				{
					if(abs(i-j)==1 && isValid(x+i,y+j)){
						// cout<<"x+i "<<(x+i)<<" y+j "<<(y+j)<<endl;
						if(mod[nT][x+i][y+j]!=-1 && ((x+i)!=gi || (y+j)!=gj) ){
							 // cout<<"got it x+i "<<(x+i)<<" y+j "<<(y+j)<<endl;
							myQ.push(make_pair(make_pair(x+i,y+j),tim+1));
						}
						else if(mod[nT][x+i][y+j]!=-1 && (x+i)==gi && (y+j)==gj){
							ans=tim+1;
							foundA=true;break;
						}
					}
				}
			}
		}
		myQ=queue<ppi>();
		if(ans!=-1)
			cout<<"Case #"<<cas<<": "<<ans<<endl;
		else
			cout<<"Case #"<<cas<<": impossible"<<endl;
	}
	return 0;
}