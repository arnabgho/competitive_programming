#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;
//0 no
//1 yes
//2 right
//3 down
int arr[1005][1005];
int main(){
	int i,j,t,n,ans;
	char ch;
	scanf("%d",&t);
	while(t--){
		ans=0;
		scanf("%d",&n);
		for(i=1;i<=n;i++){
			for(j=1;j<=n;j++){
				//scanf("%c",&ch);
				cin>>ch;
				if(ch=='#')
					arr[i][j]=0;
				else
					arr[i][j]=1;
			}	
			//scanf("\n");
		}	


		for(i=1;i<=n+1;i++)
			arr[n+1][i]=1;
		for(i=1;i<=n+1;i++)
			arr[i][n+1]=1;
		/*
		for(i=1;i<=n+1;i++){
			for(j=1;j<=n+1;j++){
				cout<<arr[i][j]<<"\t";
			}
			cout<<endl;
		}
		*/
		for(i=n;i>=1;i--){
			for(j=n;j>=1;j--){

				if((arr[i+1][j]==1)&&(arr[i][j+1]==1) && arr[i][j]){
					ans++;
					arr[i][j]=1;
				}
				else if((arr[i][j+1]==2)&&(arr[i+1][j]==1) && arr[i][j]){
					ans++;
					arr[i][j]=1;
				}
				else if((arr[i][j+1]==1)&&(arr[i+1][j]==3) && arr[i][j]){
					ans++;
					arr[i][j]=1;
				}
				else if((arr[i][j+1]==2)&&(arr[i+1][j]==3) && arr[i][j]){
					ans++;
					arr[i][j]=1;
				}
				else if((arr[i][j+1]==1||arr[i][j+1]==2) && arr[i+1][j]==0 && arr[i][j]){
					arr[i][j]=2;
				}
				else if((arr[i+1][j]==1||arr[i+1][j]==3) && arr[i][j+1]==0 && arr[i][j]){
					arr[i][j]=3;
				}
				else{
					arr[i][j]=0;
				}

			}

		}
		/*
		for(i=1;i<=n+1;i++){
			for(j=1;j<=n+1;j++){
				cout<<arr[i][j]<<"\t";
			}
			cout<<endl;
		}
		*/
		printf("%d\n",ans);
	}
	return 0;
}