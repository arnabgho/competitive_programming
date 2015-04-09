#include <stdio.h>
#include <iostream>

using namespace std;

int mat[100][100],arr[100][100][4],n,m;
int pre(int which,int i, int j)
{
if(i>=0 && i<n && j>=0 && j<m)
{
return arr[i][j][which];
}
return 0;
}
int main()
{
//if you use cin or cout then use ios given in next line
//ios_base::sync_with_stdio(0);
int t,i,j,a,b,c,k;
cin>>t;
while(t--){
cin>>n>>m;
 
for(i=0;i<n;++i)
{
for(j=0;j<m;++j)
cin>>mat[i][j];
}	
 
for(i=0;i<n;++i)
{

for(j=0;j<m;++j)
{
if(mat[i][j]<0)
arr[i][j][0]=arr[i][j][1]=mat[i][j];
else
{
arr[i][j][0]+=pre(0,i-1,j-1)+mat[i][j];
arr[i][j][1]+=pre(1,i-1,j+1)+mat[i][j];
}
}
}
 
for(i=n-1;i>=0;--i)
{
for(j=0;j<m;++j)
{
if(mat[i][j]<0)
arr[i][j][0]=arr[i][j][1]=mat[i][j];
else
{
arr[i][j][2]+=pre(2,i+1,j-1)+mat[i][j];
arr[i][j][3]+=pre(3,i+1,j+1)+mat[i][j];
}
}
}
 
int mini,maxi= 0;
for(i=0;i<n;++i)
{
for(j=0;j<m;++j)
{
mini=arr[i][j][3];

for(k=0;k<3;k++)
{
mini= min(mini,arr[i][j][k]);
}
maxi= max(maxi,mini);
}
}
if(maxi==0)
cout<< '0'<<endl;
else
cout<<(2*maxi -1)<<endl;

}
return 0;

}