#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string.h>
using namespace std;
struct entry{
	int lcs;
	int seg;
	int consider;
};
struct entry arr[1001][1001];



int max(int a,int b){
	return a>b ? a:b;
}

int main(){
	int i,j,lena,c,t,lenb,p,q;
	string a,b;
	c=0;
	scanf("%d",&t);
	//scanf("%s",s);
	while(c++<t){
		cin>>a;
		cin>>b;
		lena=a.size();
		lenb=b.size();
		for(i=0;i<=lena;i++){
			arr[i][0].lcs=0;
			arr[i][0].seg=0;
			arr[i][0].consider=0;
		}
		for(j=0;j<=lenb;j++){
			arr[j][0].lcs=0;
			arr[j][0].seg=0;
			arr[j][0].consider=0;
		}

		for(i=1;i<=lena;i++){
			for(j=1;j<=lenb;j++){
				if(a[i-1]==b[j-1]){
					arr[i][j].lcs=arr[i-1][j-1].lcs+1;
					if(arr[i-1][j-1].seg==0){
						arr[i][j].seg=1;
					}					
					else{
						arr[i][j].seg=arr[i-1][j-1].seg+1;
					}					
				}
				else{
					arr[i][j].lcs=max(arr[i-1][j].lcs,arr[i][j-1].lcs);
					arr[i][j].seg=0;
				}
			}		
		}
		for(i=0;i<=lena;i++){

			for(j=0;j<=lenb;j++){
				printf("%d,%d  ",arr[i][j].lcs,arr[i][j].seg);
			}
			printf("\n");
		}
	}
	return 0;
}
